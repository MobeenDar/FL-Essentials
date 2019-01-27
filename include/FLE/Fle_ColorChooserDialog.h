#pragma once
#ifndef Fle_ColorChooserDialog_h__
#define Fle_ColorChooserDialog_h__

/*********************************************************************************
created:	2017/11/22   04:02AM
filename: 	Fle_ColorChooserDialog.h
file base:	Fle_ColorChooserDialog
file ext:	h
author:		Furqan Ullah (Post-doc, Ph.D.)
website:    http://real3d.pk
CopyRight:	All Rights Reserved

purpose:	Customized standard color chooser that creates a color chooser
inside of a dialog box with OK, Cancel, and Default buttons.

usage example:
Fle_ColorChooserDialog dialog(305, 240, 1.0, 0.0, 1.0, "Point Color");
if (dialog.exec())
{
	p->setColor(dialog.getChooser()->r(), dialog.getChooser()->g(), dialog.getChooser()->b());
}

/**********************************************************************************
FL-ESSENTIALS (FLE) - FLTK Utility Widgets
Copyright (C) 2014-2019 REAL3D

This file and its content is protected by a software license.
You should have received a copy of this license with this file.
If not, please contact Dr. Furqan Ullah immediately:
**********************************************************************************/

#include <FLE/Fle_Export.h>
#include <FLE/Fle_Dialog.h>
#include <FLE/Fle_Layout.h>
#include <FLE/Fle_ColorChooser.h>

namespace R3D
{

class FL_ESSENTIALS_EXPORT Fle_ColorChooserDialog
{
public:
	// Description:
	// Constructor to create a color choose dialog by specifying the width, height, default color, and its title.
	Fle_ColorChooserDialog(int _w = 305, int _h = 240, double _r = 1.0, double _g = 1.0, double _b = 1.0, const char* _title = "Color Chooser");
	// Description:
	// Destructor to release data.
	virtual ~Fle_ColorChooserDialog();

	// Description:
	// Function to set the default color of the color chooser.
	void setDefaultColor(double _r, double _g, double _b);

	// Description:
	// Returns the current red value.
	// 0 <= r <= 1.
	double r() const { return p_cc->r(); }
	// Description:
	// Returns the current green value.
	// 0 <= g <= 1.
	double g() const { return p_cc->g(); }
	// Description:
	// Returns the current blue value.
	// 0 <= b <= 1.
	double b() const { return p_cc->b(); }

	// Description:
	// Function to execute the color chooser.
	// It returns 0 on Cancel button press and 1 on Ok button.
	// Note: exec will delete the widget so always create 
	// a new object in order to use it many times.
	int exec();


	// Description:
	// Function to return a pointer to first chooser.
	Fle_ColorChooser* getChooser() const { return p_cc; }
	// Description:
	// Function to return a dialog.
	Fle_Dialog* getDialog() const { return p_dialog; }

protected:
	Fle_HLayout* p_layout;
	Fle_Button* p_ok;
	Fle_Button* p_reset;
	Fle_Button* p_cancel;
	double m_default_color[3];

	Fle_ColorChooser * p_cc;
	Fle_Dialog* p_dialog;

private:
	static void close_cb(Fl_Widget* _w, void* _p);
	static void default_color_cb(Fl_Widget* _w, void* _p);
};

}

#endif // Fle_ColorChooserDialog_h__