#pragma once
#ifndef Fle_InputSlider_h__
#define Fle_InputSlider_h__

/*********************************************************************************
created:	2017/01/29   02:58AM
filename: 	Fle_InputSlider.h
file base:	Fle_InputSlider
file ext:	h
author:		Furqan Ullah (Post-doc, Ph.D.)
website:    http://real3d.pk
CopyRight:	All Rights Reserved

purpose:	customized FLTK input slider with an input widget.

/**********************************************************************************
FL-ESSENTIALS (FLE) - FLTK Utility Widgets
Copyright (C) 2014-2019 REAL3D

This file and its content is protected by a software license.
You should have received a copy of this license with this file.
If not, please contact Dr. Furqan Ullah immediately:
**********************************************************************************/
/*********************************************************************************
Usage example:

Fle_InputSlider* s = new Fle_InputSlider(10, 10, 300, 25, "Slider");
s->box(FL_UP_BOX);
s->type(FL_HOR_SLIDER);
s->value(1);
s->step(1);
s->bounds(0, 99);
s->tooltip("This slider gives you integer values.");
s->set_callback(slider_cb);
**********************************************************************************/

#include <FLE/Fle_Export.h>
#include <FLE/Fle_Slider.h>

#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Int_Input.H>

namespace R3D
{

/************************************************************************/
/* Class to create a slider with an input widget for handling int type  */
/************************************************************************/
class FL_ESSENTIALS_EXPORT Fle_InputSlider : public Fl_Group
{

public:
	// Description:
	// Constructor to create a new slider widget using the position, size, and label string.
	// _textbox_width is the width of the input/text widget.
	Fle_InputSlider(int _x, int _y, int _w, int _h, const char* _l = 0, int _textbox_width = 40);

	// Description:
	// Function to set the box type.
	// Default value is FL_UP_BOX.
	void box(Fl_Boxtype _type);
	// Description:
	// Function to get the box type.
	// Default value is FL_UP_BOX.
	Fl_Boxtype box() const;
	// Description:
	// Function to set the type of the slider.
	// Default value is FL_HOR_SLIDER.
	void type(uchar _t);
	// Description:
	// Function to set the type of the slider.
	// Default value is FL_HOR_SLIDER.
	uchar type() const;
	// Description:
	// Function to set the value.
	// Default value is 0.
	void value(int _val);
	// Description:
	// Function to get the value.
	// Default value is 0.
	int value() const;
	// Description:
	// Function to set the incremental step value.
	void step(int _step);
	// Description:
	// Function to set the minimum value.
	// Default value is 0.
	void minimum(int _val);
	// Description:
	// Function to get the minimum value.
	// Default value is 0.
	int  minimum() const;
	// Description:
	// Function to set the maximum value.
	// Default value is 0.
	void maximum(int _val);
	// Description:
	// Function to get the maximum value.
	// Default value is 0.
	int  maximum() const;
	// Description:
	// Function to set the bounds of the slider.
	void bounds(int _min, int _max);

	// Description:
	// Function to set the slider's color.
	void color(Fl_Color _c);
	// Description:
	// Function to get the slider's color.
	Fl_Color color() const;
	// Description:
	// Function to set color to the moving piece of slider.
	void selection_color(Fl_Color _c);
	// Description:
	// Function to get color of the moving piece of slider.
	Fl_Color selection_color() const;
	// Description:
	// Function to set color to the input text.
	void textcolor(Fl_Color _c);
	// Description:
	// Function to get color of the input text.
	Fl_Color textcolor() const;
	// Description:
	// Function to set input text's size.
	void textsize(int _size);
	// Description:
	// Function to get input text's size.
	int textsize() const;

	// Description:
	// Function to set callback function that should be called 
	// whenever the slider's or input value is changed.
	void set_callback(void(*_f)(int, void*), void*);

	// Description:
	// Function to get a pointer to slider.
	Fle_Slider* getSlider() const;
	// Description:
	// Function to get a pointer to input widget.
	Fl_Int_Input* getInput() const;

private:
	// Description:
	// Function to process slider's value.
	void slider_cb();
	// Description:
	// Static function to process slider's callback.
	static void slider_cb_(Fl_Widget* _w, void* _p);
	// Description:
	// Function to process input's value.
	void input_cb();
	// Description:
	// Static function to process input's callback.
	static void input_cb_(Fl_Widget* _w, void* _p);

	Fle_Slider* p_slider;
	Fl_Int_Input* p_input;
	typedef void(*funcptr)(int _v, void* _p);

#if (_MSC_VER > 1600)
	funcptr p_func = nullptr;		// Note: never forget to initialize it with nullptr, otherwise there will be an exception in vs2017.
	void* p_ptr = nullptr;
#else
	funcptr p_func;
	void* p_ptr;
#endif

	int m_init_value;
	int m_step;
};

}

#endif // Fle_InputSlider_h__