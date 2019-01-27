/*********************************************************************************
created:	2017/01/28   03:26AM
filename: 	Fle_Core.h
file base:	Fle_Core
file ext:	h
author:		Furqan Ullah (Post-doc, Ph.D.)
website:    http://real3d.pk
CopyRight:	All Rights Reserved

purpose:	Core functionalities of Fle lib.

/**********************************************************************************
FL-ESSENTIALS (FLE) - FLTK Utility Widgets
Copyright (C) 2014-2019 REAL3D

This file and its content is protected by a software license.
You should have received a copy of this license with this file.
If not, please contact Dr. Furqan Ullah immediately:
**********************************************************************************/

#include <FLE/Fle_Core.h>

#include <FL/Fl.H>
#include <FL/gl.h>						// needed for OpenGL
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_File_Icon.H>
#include <FL/Fl_Tooltip.H>

using namespace R3D;

static int __disable_escape_key(int _event)
{
	if (_event == FL_SHORTCUT && Fl::event_key(FL_Escape)) 
		return 1;

	return 0;
}

void Fle_Core::init()
{
	/************************************************************************/
	// FLTK default initialization.
	Fl::scheme("gleam");						// theme of FLTK widgets.
	Fl::visual(FL_RGB);
	Fl::gl_visual(FL_RGB);
	Fl::use_high_res_GL(1);
	Fl::visible_focus(0);						// disable dotted rectangle to focused widget.
	Fl::set_font(0, "Segoe UI");				// default windows font
	Fl::add_handler(__disable_escape_key);
	Fl::menu_linespacing(10);					// vertical spacing between menu items.
	Fl_File_Icon::load_system_icons();			// load default system icons (for file browser)
	Fl_Tooltip::delay(0.5f);
	FL_NORMAL_SIZE = 13;
	Fl_Tooltip::size(11);
	Fl_Tooltip::color(fl_rgb_color(240, 240, 240));
	Fl_Tooltip::textcolor(fl_rgb_color(87, 87, 87));
	Fl_Tooltip::margin_width(6);
	Fl_Tooltip::margin_height(6);
	fl_register_images();						// Initialize FLTK image lib (essential)

	Fl_Image::scaling_algorithm(Fl_RGB_Scaling::FL_RGB_SCALING_BILINEAR);
	Fl_Image::RGB_scaling(Fl_RGB_Scaling::FL_RGB_SCALING_BILINEAR);
	/************************************************************************/
}

int Fle_Core::exec()
{
	return Fl::run();
}