/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2002-2018 The Open Watcom Contributors. All Rights Reserved.
*    Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
*
*  ========================================================================
*
*    This file contains Original Code and/or Modifications of Original
*    Code as defined in and that are subject to the Sybase Open Watcom
*    Public License version 1.0 (the 'License'). You may not use this file
*    except in compliance with the License. BY USING THIS FILE YOU AGREE TO
*    ALL TERMS AND CONDITIONS OF THE LICENSE. A copy of the License is
*    provided with the Original Code and Modifications, and is also
*    available at www.sybase.com/developer/opensource.
*
*    The Original Code and all software distributed under the License are
*    distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
*    EXPRESS OR IMPLIED, AND SYBASE AND ALL CONTRIBUTORS HEREBY DISCLAIM
*    ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF
*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR
*    NON-INFRINGEMENT. Please see the License for the specific language
*    governing rights and limitations under the License.
*
*  ========================================================================
*
* Description:  WHEN YOU FIGURE OUT WHAT THIS FILE DOES, PLEASE
*               DESCRIBE IT HERE!
*
****************************************************************************/


#include <stddef.h>
#include "dbgdefn.h"
#include "dbgdata.h"
#include "dbgwind.h"
#include "sortlist.h"
#include "strutil.h"
#include "wndsys.h"
#include "dbgprog.h"
#include "dbgimg.h"
#include "dbgwglob.h"
#include "dbgwinsp.h"
#include "dlgfile.h"


extern void             SetLastSym( char *to );

#define TITLE_SIZE      2

enum {
    PIECE_IMAGE,
    PIECE_SYMBOL,
    PIECE_DIP,
    PIECE_LAST
};

static gui_ord  Indents[PIECE_LAST];

#include "menudef.h"
static gui_menu_struct ImgMenu[] = {
    #include "menuimg.h"
};


static void CalcIndents( a_window *wnd )
{
    image_entry *image;
    gui_ord     max_image;
    gui_ord     max_symbol;
    gui_ord     curr;

    max_image = WndExtentX( wnd, LIT_DUI( Executable_File ) );
    max_symbol = WndExtentX( wnd, LIT_DUI( Debug_Information ) );
    for( image = DbgImageList; image != NULL; image = image->link ) {
        curr = WndExtentX( wnd, image->image_name );
        if( max_image < curr )
            max_image = curr;
        curr = WndExtentX( wnd, ImgSymFileName( image, false ) );
        if( max_symbol < curr ) {
            max_symbol = curr;
        }
    }
    Indents[PIECE_SYMBOL] = max_image + 2 * WndMaxCharX( wnd );
    Indents[PIECE_DIP] = Indents[PIECE_SYMBOL] + max_symbol + 4 * WndMaxCharX( wnd );
}

static image_entry      *ImgGetImage( int row )
{
    image_entry *image;

    image = NULL;
    if( row >= 0 ) {
        for( image = DbgImageList; image != NULL; image = image->link ) {
            if( row-- == 0 ) {
                break;
            }
        }
    }
    return( image );
}

static void     ImgInit( a_window *wnd )
{
    ImgSort();
    CalcIndents( wnd );
    WndZapped( wnd );
}

OVL_EXTERN void     ImgMenuItem( a_window *wnd, gui_ctl_id id, int row, int piece )
{
    image_entry *image;
    char        *new_name;
    char        *old_name;

    /* unused parameters */ (void)piece;

    image = ImgGetImage( row );
    switch( id ) {
    case MENU_INITIALIZE:
        WndMenuGrayAll( wnd );
        if( image != NULL ) {
            if( image->dip_handle == NO_MOD ) {
                WndMenuEnable( wnd, MENU_IMAGE_ADD_SYMBOLS, true );
            } else {
                WndMenuEnableAll( wnd );
            }
        }
        break;
    case MENU_IMAGE_ADD_SYMBOLS:
        // nyi - change sym_file
        if( image->deferred_symbols ) {
            ReLoadImgSymInfo( image );
        } else {
            new_name = DupStr( ImgSymFileName( image, true ) );
            if( !SymBrowse( &new_name ) ) {
                _Free( new_name );
            } else {
                UnLoadImgSymInfo( image, true );
                old_name = image->symfile_name;
                image->symfile_name = new_name;
                if( ReLoadImgSymInfo( image ) ) {
                    _Free( old_name );
                } else {
                    image->symfile_name = old_name;
                    _Free( new_name );
                }
            }
        }
        ImgInit( wnd );
        break;
    case MENU_IMAGE_DEL_SYMBOLS:
        UnLoadImgSymInfo( image, true );
        ImgInit( wnd );
        break;
    case MENU_IMAGE_SHOW_FUNCTIONS:
        WndGblFuncInspect( image->dip_handle );
        break;
    case MENU_IMAGE_SHOW_MODULES:
        WndModListInspect( image->dip_handle );
        break;
    case MENU_IMAGE_SHOW_GLOBALS:
        WndGblVarInspect( image->dip_handle );
        break;
    }
}

OVL_EXTERN int ImgNumRows( a_window *wnd )
{
    image_entry *image;
    int         count;

    /* unused parameters */ (void)wnd;

    count = 0;
    for( image = DbgImageList; image != NULL; image = image->link ) {
        ++count;
    }
    return( count );
}

OVL_EXTERN  bool    ImgGetLine( a_window *wnd, int row, int piece,
                             wnd_line_piece *line )
{
    image_entry         *image;

    /* unused parameters */ (void)wnd;

    line->indent = Indents[piece];
    if( row < 0 ) {
        row += TITLE_SIZE;
        switch( row ) {
        case 0:
            line->tabstop = false;
            switch( piece ) {
            case PIECE_IMAGE:
                line->text = LIT_DUI( Executable_File );
                return( true );
            case PIECE_SYMBOL:
                line->text = LIT_DUI( Debug_Information );
                return( true );
            case PIECE_DIP:
                line->text = LIT_DUI( Debug_Information_Type );
                return( true );
            default:
                return( false );
            }
        case 1:
            if( piece != 0 )
                return( false );
            SetUnderLine( wnd, line );
            return( true );
        default:
            return( false );
        }
    } else {
        line->tabstop = false;
        line->use_prev_attr = true;
        line->extent = WND_MAX_EXTEND;
        image = ImgGetImage( row );
        if( image == NULL )
            return( false );
        switch( piece ) {
        case PIECE_IMAGE:
            line->text = image->image_name;
            line->tabstop = true;
            line->use_prev_attr = false;
            return( true );
        case PIECE_SYMBOL:
            line->text = ImgSymFileName( image, false );
            return( true );
        case PIECE_DIP:
            if( image->dip_handle == NO_MOD ) {
                line->text = " ";
            } else {
                line->text = DIPImageName( image->dip_handle );
            }
            return( true );
        }
    }
    return( false );
}

OVL_EXTERN void     ImgRefresh( a_window *wnd )
{
    ImgInit( wnd );
}


OVL_EXTERN bool ImgWndEventProc( a_window * wnd, gui_event gui_ev, void *parm )
{
    /* unused parameters */ (void)parm;

    switch( gui_ev ) {
    case GUI_INIT_WINDOW:
        ImgInit( wnd );
        return( true );
    case GUI_RESIZE:
        ImgInit( wnd );
        return( true );
    case GUI_DESTROY:
        return( true );
    }
    return( false );
}

wnd_info ImgInfo = {
    ImgWndEventProc,
    ImgRefresh,
    ImgGetLine,
    ImgMenuItem,
    NoScroll,
    NoBegPaint,
    NoEndPaint,
    WndFirstMenuItem,
    ImgNumRows,
    NoNextRow,
    NoNotify,
    ChkFlags,
    UP_SYM_CHANGE,
    DefPopUp( ImgMenu )
};

a_window *WndImgOpen( void )
{
    return( DbgTitleWndCreate( LIT_DUI( WindowImages ), &ImgInfo, WND_IMAGE,
            NULL, &ImgIcon, TITLE_SIZE, true ) );
}
