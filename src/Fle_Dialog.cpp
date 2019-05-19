/*********************************************************************************
created:	2017/01/30   09:42AM
filename: 	Fle_StatusBar.h
file base:	Fle_StatusBar
file ext:	h
author:		Furqan Ullah (Post-doc, Ph.D.)
website:    http://real3d.pk
CopyRight:	All Rights Reserved

purpose:	StatusBar class to create a horizontal kind of bar which contains various
widgets to be added in the status bar. Widgets will be added from the most
left side by default.

/**********************************************************************************
FL-ESSENTIALS (FLE) - FLTK Utility Widgets
Copyright (C) 2014-2019 REAL3D

This file and its content is protected by a software license.
You should have received a copy of this license with this file.
If not, please contact Dr. Furqan Ullah immediately:
**********************************************************************************/

#include <FLE/Fle_Dialog.h>
#include <FLE/Fle_Input.h>
#include <FLE/Fle_Spinner.h>
#include <FLE/Fle_FloatInputSlider.h>
#include <FLE/Fle_FileDialog.h>

#include <FL/Fl_Button.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Help_View.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Check_Button.H>
#include "FLE/Fle_Widgets.h"

using namespace R3D;

Fle_Dialog::Fle_Dialog(int _x, int _y, int _w, int _h, const char* _title, int _status_bar_height, int _x_margin, int _y_margin) :
	Fle_Window(_x, _y, _w, _h, _title),
	m_leftmargin(0),
	m_rightmargin(0),
	m_topmargin(0),
	m_bottommargin(0),
	p_ok(nullptr),
	p_cancel(nullptr)
{
	Fle_Window::color(fl_rgb_color(74, 84, 89));
	Fle_Window::begin();
	p_main_vlayout = new Fle_VLayout(_x_margin, _y_margin, _w - _x_margin - _x_margin, _h - _y_margin - _y_margin);
	p_main_vlayout->color(fl_rgb_color(74, 84, 89));

	p_main_vlayout->begin();
	p_central_hlayout = new Fle_VHLayout(0, 0, _w, _h - _status_bar_height);
	p_central_hlayout->setBackgroundColor(74, 84, 89);
	p_central_hlayout->getCentralLayout()->setBackgroundColor(74, 84, 89);
	p_central_hlayout->getCentralLayout()->getTopLayout()->setSpacing(10);
	p_central_hlayout->getCentralLayout()->getBottomLayout()->setSpacing(10);
	p_central_hlayout->getCentralLayout()->setMargins(10, 10, 10, 0);
	p_main_vlayout->end();

	p_main_vlayout->begin();

	// a separator line.
	Fle_Box* b = new Fle_Box(0, 0, _w, 1);
	b->box(FL_FLAT_BOX);
	b->color(fl_rgb_color(142, 142, 142));

	p_statusbar_vhlayout = new Fle_VHLayout(0, 0, _w, _status_bar_height);
	p_statusbar_vhlayout->setBackgroundColor(74, 84, 89);
	p_statusbar_vhlayout->getCentralLayout()->setBackgroundColor(74, 84, 89);
	p_statusbar_vhlayout->getCentralLayout()->setMargins(10, 20, 10, 0);
	p_main_vlayout->end();

	p_main_vlayout->resizable(p_central_hlayout);
	Fle_Window::end();
}

Fle_Dialog::Fle_Dialog(int _w, int _h, const char* _title, int _status_bar_height, int _x_margin, int _y_margin) :
	Fle_Window(0, 0, _w, _h, _title),
	m_leftmargin(0),
	m_rightmargin(0),
	m_topmargin(0),
	m_bottommargin(0),
	p_ok(nullptr),
	p_cancel(nullptr)
{
	Fle_Window::color(fl_rgb_color(74, 84, 89));
	Fle_Window::begin();
	p_main_vlayout = new Fle_VLayout(_x_margin, _y_margin, _w - _x_margin - _x_margin, _h - _y_margin - _y_margin);
	p_main_vlayout->color(fl_rgb_color(74, 84, 89));

	p_main_vlayout->begin();
	p_central_hlayout = new Fle_VHLayout(0, 0, _w, _h - _status_bar_height);
	p_central_hlayout->setBackgroundColor(74, 84, 89);
	p_central_hlayout->getCentralLayout()->setBackgroundColor(74, 84, 89);
	p_central_hlayout->getCentralLayout()->getTopLayout()->setSpacing(10);
	p_central_hlayout->getCentralLayout()->getBottomLayout()->setSpacing(10);
	p_central_hlayout->getCentralLayout()->setMargins(10, 10, 10, 0);
	p_main_vlayout->end();

	p_main_vlayout->begin();

	// a separator line.
	Fle_Box* b = new Fle_Box(0, 0, _w, 1);
	b->box(FL_FLAT_BOX);
	b->color(fl_rgb_color(142, 142, 142));

	p_statusbar_vhlayout = new Fle_VHLayout(0, 0, _w, _status_bar_height);
	p_statusbar_vhlayout->setBackgroundColor(74, 84, 89);
	p_statusbar_vhlayout->getCentralLayout()->setBackgroundColor(74, 84, 89);
	p_statusbar_vhlayout->getCentralLayout()->setMargins(10, 20, 10, 0);
	p_main_vlayout->end();

	p_main_vlayout->resizable(p_central_hlayout);
	Fle_Window::end();

	// positioned at center of the screen.
	int X, Y, W, H;
	Fl::screen_work_area(X, Y, W, H);
	position(X + W / 2 - _w / 2, Y + H / 2 - _h / 2);
}

Fle_Dialog::~Fle_Dialog()
{
}

void Fle_Dialog::begin()
{
	p_central_hlayout->begin();
}
void Fle_Dialog::end()
{
	p_central_hlayout->end();
	Fl_Window::end();
}

void Fle_Dialog::setBackgroundColor(Fl_Color _color)
{
	Fle_Window::color(_color);
	getMainLayout()->color(_color);
	getCentralLayout()->setBackgroundColor(_color);
	getCentralLayout()->getCentralLayout()->setBackgroundColor(_color);
	getStatusBar()->setBackgroundColor(_color);
	getStatusBar()->getCentralLayout()->setBackgroundColor(_color);
}
void Fle_Dialog::setBackgroundColor(uchar _red, uchar _green, uchar _blue)
{
	Fle_Window::color(fl_rgb_color(_red, _green, _blue));
	getMainLayout()->color(fl_rgb_color(_red, _green, _blue));
	getCentralLayout()->setBackgroundColor(_red, _green, _blue);
	getCentralLayout()->getCentralLayout()->setBackgroundColor(_red, _green, _blue);
	getStatusBar()->setBackgroundColor(_red, _green, _blue);
	getStatusBar()->getCentralLayout()->setBackgroundColor(_red, _green, _blue);
}

void Fle_Dialog::setStatusBarFixedHeight(int _h)
{
	p_central_hlayout->size(p_main_vlayout->w(), p_main_vlayout->h() - _h);
	p_statusbar_vhlayout->size(p_main_vlayout->w(), _h);
}

static void static_dialog_cb(Fl_Widget* _w, void* _p)
{
	Fle_Dialog* d = static_cast<Fle_Dialog*>(_p);
	d->hide();
	Fl::delete_widget(d);
}

int Fle_Dialog::getFloatInputSlider(int _w, int _h,
	const char* _title,
	const char* _label,
	double& _value,
	double _minimum,
	double _maximum,
	double _step,
	void(*_callback)(double, void*), void* _data,
	const char* _checkbox_label,
	bool& _checkbox)
{
	Fle_Dialog* d = new Fle_Dialog(_w, _h, _title, 58, 0, 0);
	d->callback(static_dialog_cb, d);
	d->setMargins(10, 10, 10, 10);

	Fle_HLayout* l = d->getCentralLayout()->addHLayout(22);

	l->begin();

	Fle_FloatInputSlider* s;
	if (_label)
	{
		Fle_Box* b = new Fle_Box(0, 0, Fle_Widgets::getTextWidth(_label), 22);
		b->color(fl_rgb_color(74, 84, 89));
		b->setText(_label);
		b->getFont()->setColor(fl_rgb_color(255, 255, 255));
		b->getFont()->setAlignment(FL_ALIGN_LEFT);

		s = new Fle_FloatInputSlider(0, 0, _w - b->w() - 23, 22, nullptr, 55);
	}
	else
	{
		s = new Fle_FloatInputSlider(0, 0, _w - 23, 22, nullptr, 55);
	}

	s->type(FL_HOR_SLIDER);
	s->box(FL_BORDER_BOX);
	s->color(fl_rgb_color(74 + 20, 84 + 20, 89 + 20));
	s->selection_color(fl_rgb_color(66, 192, 251));
	s->textcolor(fl_rgb_color(255, 255, 255));
	s->labelsize(12);
	s->textsize(12);
	s->value(_value);
	s->minimum(_minimum);
	s->maximum(_maximum);
	s->step(_step);
	s->set_callback(_callback, _data);
	s->getSlider()->when(FL_WHEN_CHANGED);

	l->end();

	Fl_Check_Button* check = nullptr;
	if (_checkbox_label)
	{
		l = d->getCentralLayout()->addHLayout(30);
		l->begin();
		check = new Fl_Check_Button(0, 0, _w, 30, _checkbox_label);
		check->box(FL_FLAT_BOX);
		check->down_box(FL_FRAME_BOX);		
		check->color(fl_rgb_color(74, 84, 89));
		check->selection_color(fl_rgb_color(78, 196, 203));
		if (_checkbox) check->value(1);
		else check->value(0);
		check->labelsize(12);
		check->labelcolor(fl_rgb_color(255, 255, 255));
		check->clear_visible_focus();
		l->end();
	}

	Fle_HLayoutLR* hl1 = d->getStatusBar()->addLayoutLR(23);
	hl1->setBackgroundColor(74, 84, 89);

	hl1->beginRight();

	Fle_Button* ok = new Fle_Button(0, 0, 90, 22, "OK");
	ok->color(fl_rgb_color(74, 84, 89));
	ok->selection_color(fl_rgb_color(74, 84, 89));
	ok->labelcolor(fl_rgb_color(255, 255, 255));
	ok->labelsize(12);
	d->setOkButton(ok);

	Fle_Button* cancel = new Fle_Button(0, 0, 90, 22, "Cancel");
	cancel->color(fl_rgb_color(74, 84, 89));
	cancel->selection_color(fl_rgb_color(74, 84, 89));
	cancel->labelcolor(fl_rgb_color(255, 255, 255));
	cancel->labelsize(12);
	d->setCancelButton(cancel);

	hl1->end();

	// set dialog's margins.
	d->getCentralLayout()->getCentralLayout()->setMargins(10, 10, 15, 0);
	// set statusbar's margins and height.
	d->getStatusBar()->getCentralLayout()->setMargins(10, 10, 10, 0);
	d->setStatusBarFixedHeight(58);

	d->resizable(0);
	d->hotspot(ok);
	d->set_modal();
	d->show();
	int X, Y, W, H;
	Fl::screen_work_area(X, Y, W, H);
	d->position(X + W / 2 - _w / 2, Y + H / 2 - _h / 2);

	while (d->shown())
	{
		Fl::wait();
		Fl_Widget* o;
		while (((o = Fl::readqueue())) && d->shown())
		{
			if (o == ok)
			{
				_value = s->value();
				if (check)
				{
					if (check->value() == 1) _checkbox = true;
					else _checkbox = false;
				}
				Fl::delete_widget(d);
				return 1;
			}
			else
			{
				if (o == cancel || o == d)
				{
					d->hide();
					Fl::delete_widget(d);
					return 0;
				}
			}
		}
	}
	return 0;
}

int Fle_Dialog::getFloatInputSlider(int _w, int _h,
	const char* _title,
	const char* _label,
	double& _value,
	double _minimum,
	double _maximum,
	double _step,
	void(*_callback)(double, void*), void* _data)
{
	bool b = false;
	return getFloatInputSlider(_w, _h, _title, _label, _value, _minimum, _maximum, _step, _callback, _data, nullptr, b);
}

int Fle_Dialog::getNumber(int _w, int _h, 
	const char* _title, 
	const char* _label, 
	double& _value, 
	double _minimum, 
	double _maximum, 
	double _step,
	const char* _checkbox_label,
	bool& _checkbox)
{
	Fle_Dialog* d = new Fle_Dialog(_w, _h, _title, 58, 0, 0);
	d->callback(static_dialog_cb, d);
	d->setMargins(10, 10, 10, 10);

	Fle_HLayout* l = d->getCentralLayout()->addHLayout(25);

	l->begin();

	Fle_Spinner* s;
	if (_label)
	{
		Fle_Box* b = new Fle_Box(0, 0, _w - 132, 25);
		b->color(fl_rgb_color(74, 84, 89));
		b->setText(_label);
		b->getFont()->setColor(fl_rgb_color(255, 255, 255));
		b->getFont()->setAlignment(FL_ALIGN_LEFT);

		s = new Fle_Spinner(0, 0, 100, 25);
	}
	else
	{
		s = new Fle_Spinner(0, 0, _w - 23, 25);
	}

	s->type(FL_FLOAT_INPUT);
	s->box(FL_FLAT_BOX);
	s->color(fl_rgb_color(74 + 20, 84 + 20, 89 + 20));
	s->getUpButton().color(s->color());
	s->getDownButton().color(s->color());
	s->selection_color(fl_rgb_color(255, 255, 255));
	s->textcolor(fl_rgb_color(255, 255, 255));
	s->value(_value);
	s->minimum(_minimum);
	s->maximum(_maximum);
	s->step(_step);
	s->when(FL_WHEN_CHANGED);

	l->end();

	Fl_Check_Button* check = nullptr;
	if (_checkbox_label)
	{
		l = d->getCentralLayout()->addHLayout(30);
		l->begin();
		check = new Fl_Check_Button(0, 0, _w, 30, _checkbox_label);
		check->box(FL_FLAT_BOX);
		check->down_box(FL_FRAME_BOX);
		check->color(fl_rgb_color(74, 84, 89));
		check->selection_color(fl_rgb_color(78, 196, 203));
		if (_checkbox) check->value(1);
		else check->value(0);
		check->labelsize(12);
		check->labelcolor(fl_rgb_color(255, 255, 255));
		check->clear_visible_focus();
		l->end();
	}

	Fle_HLayoutLR* hl1 = d->getStatusBar()->addLayoutLR(23);
	hl1->setBackgroundColor(74, 84, 89);

	hl1->beginRight();

	Fle_Button* ok = new Fle_Button(0, 0, 90, 22, "OK");
	ok->color(fl_rgb_color(74, 84, 89));
	ok->selection_color(fl_rgb_color(74, 84, 89));
	ok->labelcolor(fl_rgb_color(255, 255, 255));
	ok->labelsize(12);
	d->setOkButton(ok);

	Fle_Button* cancel = new Fle_Button(0, 0, 90, 22, "Cancel");
	cancel->color(fl_rgb_color(74, 84, 89));
	cancel->selection_color(fl_rgb_color(74, 84, 89));
	cancel->labelcolor(fl_rgb_color(255, 255, 255));
	cancel->labelsize(12);
	d->setCancelButton(cancel);

	hl1->end();

	// set dialog's margins.
	d->getCentralLayout()->getCentralLayout()->setMargins(10, 10, 15, 0);
	// set statusbar's margins and height.
	d->getStatusBar()->getCentralLayout()->setMargins(10, 10, 10, 0);
	d->setStatusBarFixedHeight(58);

	d->resizable(0);
	d->hotspot(ok);
	d->set_modal();
	d->show();
	int X, Y, W, H;
	Fl::screen_work_area(X, Y, W, H);
	d->position(X + W / 2 - _w / 2, Y + H / 2 - _h / 2);

	while (d->shown())
	{
		Fl::wait();
		Fl_Widget* o;
		while (((o = Fl::readqueue())) && d->shown())
		{
			if (o == ok)
			{
				_value = s->value();
				if (check)
				{
					if (check->value() == 1) _checkbox = true;
					else _checkbox = false;
				}
				Fl::delete_widget(d);
				return 1;
			}
			else
			{
				if (o == cancel || o == d)
				{
					d->hide();
					Fl::delete_widget(d);
					return 0;
				}
			}
		}
	}
	return 0;
}
int Fle_Dialog::getNumber(int _w, int _h,
	const char* _title,
	const char* _label,
	double& _value,
	double _minimum,
	double _maximum,
	double _step)
{
	bool b = false;
	return getNumber(_w, _h, _title, _label, _value, _minimum, _maximum, _step, nullptr, b);
}

int Fle_Dialog::getNumbers(int _w, int _h, const char* _title,
	const std::vector<const char*>& _labels, 
	std::vector<double>& _values, 
	const std::vector<double>& _minimums, 
	const std::vector<double>& _maximums, 
	const std::vector<double>& _steps,
	const char* _checkbox_label,
	bool& _checkbox)
{
	Fle_Dialog* d = new Fle_Dialog(_w, _h, _title, 58, 0, 0);
	d->callback(static_dialog_cb, d);
	d->setMargins(10, 10, 10, 10);

	std::vector<Fle_Spinner*> s(_labels.size());
	for (std::size_t i = 0; i < _labels.size(); i++)
	{
		Fle_HLayout* l = d->getCentralLayout()->addHLayout(25);

		l->begin();

		Fle_Box* b = new Fle_Box(0, 0, _w - 132, 25);
		b->color(fl_rgb_color(74, 84, 89));
		b->setText(_labels[i]);
		b->getFont()->setColor(fl_rgb_color(255, 255, 255));
		b->getFont()->setAlignment(FL_ALIGN_LEFT);

		s[i] = new Fle_Spinner(0, 0, 100, 25);
		s[i]->type(FL_FLOAT_INPUT);
		s[i]->box(FL_UP_BOX);
		s[i]->color(fl_rgb_color(74 + 20, 84 + 20, 89 + 20));
		s[i]->getUpButton().color(s[i]->color());
		s[i]->getDownButton().color(s[i]->color());
		s[i]->selection_color(fl_rgb_color(255, 255, 255));
		s[i]->textcolor(fl_rgb_color(255, 255, 255));
		s[i]->value(_values[i]);
		s[i]->minimum(_minimums[i]);
		s[i]->maximum(_maximums[i]);
		s[i]->step(_steps[i]);
		s[i]->when(FL_WHEN_CHANGED);

		//s[i]->box(FL_FLAT_BOX);
		//s[i]->color(fl_rgb_color(74, 84, 89));
		//s[i]->textcolor(fl_rgb_color(255, 255, 255));
		//s[i]->textsize(14);
		//s[i]->getDownButton().color(fl_rgb_color(74, 84, 89));
		//s[i]->getDownButton().box(_FL_GTK_UP_BOX);
		//s[i]->getUpButton().color(fl_rgb_color(74, 84, 89));
		//s[i]->getUpButton().box(_FL_GTK_UP_BOX);

		l->end();
	}

	Fl_Check_Button* check = nullptr;
	if (_checkbox_label)
	{
		Fle_HLayout* l = d->getCentralLayout()->addHLayout(30);
		l->begin();
		check = new Fl_Check_Button(0, 0, _w, 30, _checkbox_label);
		check->box(FL_FLAT_BOX);
		check->down_box(FL_FRAME_BOX);
		check->color(fl_rgb_color(74, 84, 89));
		check->selection_color(fl_rgb_color(78, 196, 203));
		if (_checkbox) check->value(1);
		else check->value(0);
		check->labelsize(12);
		check->labelcolor(fl_rgb_color(255, 255, 255));
		check->clear_visible_focus();
		l->end();
	}

	Fle_HLayoutLR* hl1 = d->getStatusBar()->addLayoutLR(23);
	hl1->setBackgroundColor(74, 84, 89);

	hl1->beginRight();

	Fle_Button* ok = new Fle_Button(0, 0, 90, 22, "OK");
	ok->color(fl_rgb_color(74, 84, 89));
	ok->selection_color(fl_rgb_color(74, 84, 89));
	ok->labelcolor(fl_rgb_color(255, 255, 255));
	ok->labelsize(12);
	d->setOkButton(ok);

	Fle_Button* cancel = new Fle_Button(0, 0, 90, 22, "Cancel");
	cancel->color(fl_rgb_color(74, 84, 89));
	cancel->selection_color(fl_rgb_color(74, 84, 89));
	cancel->labelcolor(fl_rgb_color(255, 255, 255));
	cancel->labelsize(12);
	d->setCancelButton(cancel);

	hl1->end();

	// set dialog's margins.
	d->getCentralLayout()->getCentralLayout()->setMargins(10, 10, 15, 0);
	// set statusbar's margins and height.
	d->getStatusBar()->getCentralLayout()->setMargins(10, 10, 10, 0);
	d->setStatusBarFixedHeight(58);

	d->resizable(0);
	d->hotspot(ok);
	d->set_modal();
	d->show();
	int X, Y, W, H;
	Fl::screen_work_area(X, Y, W, H);
	d->position(X + W / 2 - _w / 2, Y + H / 2 - _h / 2);

	while (d->shown())
	{
		Fl::wait();
		Fl_Widget* o;
		while (((o = Fl::readqueue())) && d->shown())
		{
			if (o == ok)
			{
				for (std::size_t i = 0; i < _labels.size(); i++)
					_values[i] = s[i]->value();
				if (check)
				{
					if (check->value() == 1) _checkbox = true;
					else _checkbox = false;
				}
				Fl::delete_widget(d);
				return 1;
			}
			else
			{
				if (o == cancel || o == d)
				{
					d->hide();
					Fl::delete_widget(d);
					return 0;
				}
			}
		}
	}
	return 0;
}
int Fle_Dialog::getNumbers(int _w, int _h, const char* _title,
	const std::vector<const char*>& _labels,
	std::vector<double>& _values,
	const std::vector<double>& _minimums,
	const std::vector<double>& _maximums,
	const std::vector<double>& _steps)
{
	bool b = false;
	return getNumbers(_w, _h, _title, _labels, _values, _minimums, _maximums, _steps, nullptr, b);
}

int Fle_Dialog::getNumbers(int _w, int _h, const char* _title,
	const std::vector<const char*>& _labels,
	std::vector<double>& _values,
	const std::vector<double>& _minimums,
	const std::vector<double>& _maximums,
	const std::vector<double>& _steps,
	const std::vector<const char*>& _menus_lables,
	std::vector< std::vector<std::string> >& _menus)
{
	Fle_Dialog* d = new Fle_Dialog(_w, _h, _title, 58, 0, 0);
	d->callback(static_dialog_cb, d);
	d->setMargins(10, 10, 10, 10);

	std::vector<Fle_Spinner*> s(_labels.size());
	for (std::size_t i = 0; i < _labels.size(); i++)
	{
		Fle_HLayout* l = d->getCentralLayout()->addHLayout(25);

		l->begin();

		Fle_Box* b = new Fle_Box(0, 0, _w - 132, 25);
		b->color(fl_rgb_color(74, 84, 89));
		b->setText(_labels[i]);
		b->getFont()->setColor(fl_rgb_color(255, 255, 255));
		b->getFont()->setAlignment(FL_ALIGN_LEFT);

		s[i] = new Fle_Spinner(0, 0, 100, 25);
		s[i]->type(FL_FLOAT_INPUT);
		s[i]->box(FL_UP_BOX);
		s[i]->color(fl_rgb_color(74 + 20, 84 + 20, 89 + 20));
		s[i]->getUpButton().color(s[i]->color());
		s[i]->getDownButton().color(s[i]->color());
		s[i]->selection_color(fl_rgb_color(255, 255, 255));
		s[i]->textcolor(fl_rgb_color(255, 255, 255));
		s[i]->value(_values[i]);
		s[i]->minimum(_minimums[i]);
		s[i]->maximum(_maximums[i]);
		s[i]->step(_steps[i]);
		s[i]->when(FL_WHEN_CHANGED);

		//s[i]->box(FL_FLAT_BOX);
		//s[i]->color(fl_rgb_color(74, 84, 89));
		//s[i]->textcolor(fl_rgb_color(255, 255, 255));
		//s[i]->textsize(14);
		//s[i]->getDownButton().color(fl_rgb_color(74, 84, 89));
		//s[i]->getDownButton().box(_FL_GTK_UP_BOX);
		//s[i]->getUpButton().color(fl_rgb_color(74, 84, 89));
		//s[i]->getUpButton().box(_FL_GTK_UP_BOX);

		l->end();
	}

	std::vector<Fl_Choice*> choice(_menus_lables.size());
	for (std::size_t i = 0; i < _menus_lables.size(); i++)
	{
		Fle_HLayout* l = d->getCentralLayout()->addHLayout(25);

		l->begin();

		Fle_Box* b = new Fle_Box(0, 0, _w - 132, 25);
		b->color(fl_rgb_color(74, 84, 89));
		b->setText(_menus_lables[i]);
		b->getFont()->setColor(fl_rgb_color(255, 255, 255));
		b->getFont()->setAlignment(FL_ALIGN_LEFT);

		choice[i] = new Fl_Choice(0, 0, 100, 25);
		choice[i]->box(FL_FLAT_BOX);
		choice[i]->down_box(FL_FLAT_BOX);
		choice[i]->color(fl_rgb_color(74 + 20, 84 + 20, 89 + 20));
		choice[i]->color2(fl_rgb_color(253, 244, 191));
		choice[i]->textcolor(fl_rgb_color(255, 255, 255));
		choice[i]->textsize(12);
		for (std::size_t j = 0; j < _menus[i].size(); j++)
			choice[i]->add(_menus[i][j].c_str());
		choice[i]->value(0);
		choice[i]->clear_visible_focus();

		l->end();
	}

	Fle_HLayoutLR* hl1 = d->getStatusBar()->addLayoutLR(23);
	hl1->setBackgroundColor(74, 84, 89);

	hl1->beginRight();

	Fle_Button* ok = new Fle_Button(0, 0, 90, 22, "OK");
	ok->color(fl_rgb_color(74, 84, 89));
	ok->selection_color(fl_rgb_color(74, 84, 89));
	ok->labelcolor(fl_rgb_color(255, 255, 255));
	ok->labelsize(12);
	d->setOkButton(ok);

	Fle_Button* cancel = new Fle_Button(0, 0, 90, 22, "Cancel");
	cancel->color(fl_rgb_color(74, 84, 89));
	cancel->selection_color(fl_rgb_color(74, 84, 89));
	cancel->labelcolor(fl_rgb_color(255, 255, 255));
	cancel->labelsize(12);
	d->setCancelButton(cancel);

	hl1->end();

	// set dialog's margins.
	d->getCentralLayout()->getCentralLayout()->setMargins(10, 10, 15, 0);
	// set statusbar's margins and height.
	d->getStatusBar()->getCentralLayout()->setMargins(10, 10, 10, 0);
	d->setStatusBarFixedHeight(58);

	d->resizable(0);
	d->hotspot(ok);
	d->set_modal();
	d->show();
	int X, Y, W, H;
	Fl::screen_work_area(X, Y, W, H);
	d->position(X + W / 2 - _w / 2, Y + H / 2 - _h / 2);

	while (d->shown())
	{
		Fl::wait();
		Fl_Widget* o;
		while (((o = Fl::readqueue())) && d->shown())
		{
			if (o == ok)
			{
				for (std::size_t i = 0; i < _labels.size(); i++)
					_values[i] = s[i]->value();

				for (std::size_t i = 0; i < _menus.size(); i++)
				{
					std::string selected_item = _menus[i].at(choice[i]->value());
					_menus[i].clear();
					_menus[i].push_back(selected_item);
				}

				Fl::delete_widget(d);
				return 1;
			}
			else
			{
				if (o == cancel || o == d)
				{
					d->hide();
					Fl::delete_widget(d);
					return 0;
				}
			}
		}
	}
	return 0;
}

int Fle_Dialog::getNumbers(int _w, int _h, const char* _title,
	const std::vector<const char*>& _menus_lables,
	std::vector< std::vector<std::string> >& _menus,
	const std::vector<const char*>& _labels,
	std::vector<double>& _values,
	const std::vector<double>& _minimums,
	const std::vector<double>& _maximums,
	const std::vector<double>& _steps)
{
	Fle_Dialog* d = new Fle_Dialog(_w, _h, _title, 58, 0, 0);
	d->callback(static_dialog_cb, d);
	d->setMargins(10, 10, 10, 10);

	std::vector<Fl_Choice*> choice(_menus_lables.size());
	for (std::size_t i = 0; i < _menus_lables.size(); i++)
	{
		Fle_HLayout* l = d->getCentralLayout()->addHLayout(25);

		l->begin();

		Fle_Box* b = new Fle_Box(0, 0, _w - 132, 25);
		b->color(fl_rgb_color(74, 84, 89));
		b->setText(_menus_lables[i]);
		b->getFont()->setColor(fl_rgb_color(255, 255, 255));
		b->getFont()->setAlignment(FL_ALIGN_LEFT);

		choice[i] = new Fl_Choice(0, 0, 100, 25);
		choice[i]->box(FL_FLAT_BOX);
		choice[i]->down_box(FL_FLAT_BOX);
		choice[i]->color(fl_rgb_color(74 + 20, 84 + 20, 89 + 20));
		choice[i]->color2(fl_rgb_color(253, 244, 191));
		choice[i]->textcolor(fl_rgb_color(255, 255, 255));
		choice[i]->textsize(12);
		for (std::size_t j = 0; j < _menus[i].size(); j++)
			choice[i]->add(_menus[i][j].c_str());
		choice[i]->value(0);
		choice[i]->clear_visible_focus();

		l->end();
	}

	std::vector<Fle_Spinner*> s(_labels.size());
	for (std::size_t i = 0; i < _labels.size(); i++)
	{
		Fle_HLayout* l = d->getCentralLayout()->addHLayout(25);

		l->begin();

		Fle_Box* b = new Fle_Box(0, 0, _w - 132, 25);
		b->color(fl_rgb_color(74, 84, 89));
		b->setText(_labels[i]);
		b->getFont()->setColor(fl_rgb_color(255, 255, 255));
		b->getFont()->setAlignment(FL_ALIGN_LEFT);

		s[i] = new Fle_Spinner(0, 0, 100, 25);
		s[i]->type(FL_FLOAT_INPUT);
		s[i]->box(FL_UP_BOX);
		s[i]->color(fl_rgb_color(74 + 20, 84 + 20, 89 + 20));
		s[i]->getUpButton().color(s[i]->color());
		s[i]->getDownButton().color(s[i]->color());
		s[i]->selection_color(fl_rgb_color(255, 255, 255));
		s[i]->textcolor(fl_rgb_color(255, 255, 255));
		s[i]->value(_values[i]);
		s[i]->minimum(_minimums[i]);
		s[i]->maximum(_maximums[i]);
		s[i]->step(_steps[i]);
		s[i]->when(FL_WHEN_CHANGED);

		//s[i]->box(FL_FLAT_BOX);
		//s[i]->color(fl_rgb_color(74, 84, 89));
		//s[i]->textcolor(fl_rgb_color(255, 255, 255));
		//s[i]->textsize(14);
		//s[i]->getDownButton().color(fl_rgb_color(74, 84, 89));
		//s[i]->getDownButton().box(_FL_GTK_UP_BOX);
		//s[i]->getUpButton().color(fl_rgb_color(74, 84, 89));
		//s[i]->getUpButton().box(_FL_GTK_UP_BOX);

		l->end();
	}

	Fle_HLayoutLR* hl1 = d->getStatusBar()->addLayoutLR(23);
	hl1->setBackgroundColor(74, 84, 89);

	hl1->beginRight();

	Fle_Button* ok = new Fle_Button(0, 0, 90, 22, "OK");
	ok->color(fl_rgb_color(74, 84, 89));
	ok->selection_color(fl_rgb_color(74, 84, 89));
	ok->labelcolor(fl_rgb_color(255, 255, 255));
	ok->labelsize(12);
	d->setOkButton(ok);

	Fle_Button* cancel = new Fle_Button(0, 0, 90, 22, "Cancel");
	cancel->color(fl_rgb_color(74, 84, 89));
	cancel->selection_color(fl_rgb_color(74, 84, 89));
	cancel->labelcolor(fl_rgb_color(255, 255, 255));
	cancel->labelsize(12);
	d->setCancelButton(cancel);

	hl1->end();

	// set dialog's margins.
	d->getCentralLayout()->getCentralLayout()->setMargins(10, 10, 15, 0);
	// set statusbar's margins and height.
	d->getStatusBar()->getCentralLayout()->setMargins(10, 10, 10, 0);
	d->setStatusBarFixedHeight(58);

	d->resizable(0);
	d->hotspot(ok);
	d->set_modal();
	d->show();
	int X, Y, W, H;
	Fl::screen_work_area(X, Y, W, H);
	d->position(X + W / 2 - _w / 2, Y + H / 2 - _h / 2);

	while (d->shown())
	{
		Fl::wait();
		Fl_Widget* o;
		while (((o = Fl::readqueue())) && d->shown())
		{
			if (o == ok)
			{
				for (std::size_t i = 0; i < _labels.size(); i++)
					_values[i] = s[i]->value();

				for (std::size_t i = 0; i < _menus.size(); i++)
				{
					std::string selected_item = _menus[i].at(choice[i]->value());
					_menus[i].clear();
					_menus[i].push_back(selected_item);
				}

				Fl::delete_widget(d);
				return 1;
			}
			else
			{
				if (o == cancel || o == d)
				{
					d->hide();
					Fl::delete_widget(d);
					return 0;
				}
			}
		}
	}
	return 0;
}

int Fle_Dialog::getInput(int _w, int _h, const char* _title, const char* _label, std::string& _value)
{
	Fle_Dialog* d = new Fle_Dialog(_w, _h, _title, 58, 0, 0);
	d->callback(static_dialog_cb, d);
	d->setMargins(10, 10, 10, 10);

	Fle_HLayout* l = d->getCentralLayout()->addHLayout(25);

	l->begin();

	Fle_InputWidget* s = new Fle_InputWidget(0, 0, _w - 20, 25, _label);
	s->box(FL_BORDER_BOX);
	s->align(FL_ALIGN_LEFT);
	s->setRightClickPopupColor(fl_rgb_color(74, 84, 89));
	s->setRightClickPopupTextColor(fl_rgb_color(255, 255, 255));
	s->color(fl_rgb_color(74, 84, 89));
	s->textcolor(fl_rgb_color(255, 255, 255));
	s->textsize(12);
	s->value(std::string(_value).c_str());

	l->end();

	Fle_HLayoutLR* hl1 = d->getStatusBar()->addLayoutLR(23);
	hl1->setBackgroundColor(74, 84, 89);

	hl1->beginRight();

	Fle_Button* ok = new Fle_Button(0, 0, 90, 22, "OK");
	ok->color(fl_rgb_color(74, 84, 89));
	ok->selection_color(fl_rgb_color(74, 84, 89));
	ok->labelcolor(fl_rgb_color(255, 255, 255));
	ok->labelsize(12);
	d->setOkButton(ok);

	Fle_Button* cancel = new Fle_Button(0, 0, 90, 22, "Cancel");
	cancel->color(fl_rgb_color(74, 84, 89));
	cancel->selection_color(fl_rgb_color(74, 84, 89));
	cancel->labelcolor(fl_rgb_color(255, 255, 255));
	cancel->labelsize(12);
	d->setCancelButton(cancel);

	hl1->end();

	// set dialog's margins.
	d->getCentralLayout()->getCentralLayout()->setMargins(10, 10, 15, 0);
	// set statusbar's margins and height.
	d->getStatusBar()->getCentralLayout()->setMargins(10, 10, 10, 0);
	d->setStatusBarFixedHeight(58);

	d->resizable(0);
	d->hotspot(ok);
	d->set_modal();
	d->show();
	int X, Y, W, H;
	Fl::screen_work_area(X, Y, W, H);
	d->position(X + W / 2 - _w / 2, Y + H / 2 - _h / 2);

	while (d->shown())
	{
		Fl::wait();
		Fl_Widget* o;
		while (((o = Fl::readqueue())) && d->shown())
		{
			if (o == ok)
			{
				_value = s->value();
				Fl::delete_widget(d);
				return 1;
			}
			else
			{
				if (o == cancel || o == d)
				{
					d->hide();
					Fl::delete_widget(d);
					return 0;
				}
			}
		}
	}
	return 0;
}

int Fle_Dialog::getInputs(int _w, int _h, 
	const char* _title,
	const std::vector<const char*>& _labels,
	std::vector<std::string>& _values,
	Fle_Font _label_prop,
	Fl_Color _text_bkgrnd_color,
	Fl_Color _text_color)
{
	Fle_Dialog* d = new Fle_Dialog(_w, _h, _title, 58, 0, 0);
	d->callback(static_dialog_cb, d);
	d->setMargins(10, 10, 10, 10);

	// find the longest label.
	int n = Fle_Widgets::getLongestTextWidth(_labels);

	// create all the inputs.
	std::vector<Fle_InputWidget*> s(_labels.size());
	for (std::size_t i = 0; i < _labels.size(); i++)
	{
		// first, create a layout in which other widgets will be packed.
		Fle_HLayout* l = d->getCentralLayout()->addHLayout(25);

		// start packing.
		l->begin();

		// create a label at the most left size.
		Fle_Box* b = new Fle_Box(0, 0, n, 25);
		b->color(fl_rgb_color(74, 84, 89));
		b->setText(_labels[i]);
		b->getFont()->setColor(_label_prop.getColor());
		b->getFont()->setAlignment(_label_prop.getAlignment());
		b->getFont()->setFace(_label_prop.getFace());
		b->getFont()->setSize(_label_prop.getSize());

		// create a input with the adjusted size.
		s[i] = new Fle_InputWidget(0, 0, _w - b->w() - 20, 25);
		s[i]->box(FL_BORDER_BOX);
		s[i]->align(FL_ALIGN_LEFT);
		s[i]->setRightClickPopupColor(fl_rgb_color(64, 74, 79));
		s[i]->setRightClickPopupTextColor(fl_rgb_color(255, 255, 255));
		s[i]->color(_text_bkgrnd_color);
		s[i]->textcolor(_text_color);
		s[i]->textsize(12);
		s[i]->value(std::string(_values[i]).c_str());

		// end packing.
		l->end();
	}

	// now, create a layout in the statusbar for Ok and Cancel buttons.
	Fle_HLayoutLR* hl1 = d->getStatusBar()->addLayoutLR(23);
	hl1->setBackgroundColor(74, 84, 89);

	// start packing in the statusbar's layout.
	hl1->beginRight();

	// add/pack Ok button first.
	Fle_Button* ok = new Fle_Button(0, 0, 90, 22, "OK");
	ok->color(fl_rgb_color(74, 84, 89));
	ok->selection_color(fl_rgb_color(74, 84, 89));
	ok->labelcolor(fl_rgb_color(255, 255, 255));
	ok->labelsize(12);
	ok->clear_visible_focus();
	d->setOkButton(ok);

	// then, add/pack cancel button.
	Fle_Button* cancel = new Fle_Button(0, 0, 90, 22, "Cancel");
	cancel->color(fl_rgb_color(74, 84, 89));
	cancel->selection_color(fl_rgb_color(74, 84, 89));
	cancel->labelcolor(fl_rgb_color(255, 255, 255));
	cancel->labelsize(12);
	cancel->clear_visible_focus();
	d->setCancelButton(cancel);

	// end packing.
	hl1->end();

	// set dialog's margins.
	d->getCentralLayout()->getCentralLayout()->setMargins(10, 10, 15, 0);
	// set statusbar's margins and height.
	d->getStatusBar()->getCentralLayout()->setMargins(10, 10, 10, 0);
	d->setStatusBarFixedHeight(58);

	// disable resizing the window. It will disable the close button also.
	d->resizable(0);
	d->hotspot(ok);
	d->set_modal();
	d->show();
	int X, Y, W, H;
	Fl::screen_work_area(X, Y, W, H);
	d->position(X + W / 2 - _w / 2, Y + H / 2 - _h / 2);

	while (d->shown())
	{
		Fl::wait();
		Fl_Widget* o;
		while (((o = Fl::readqueue())) && d->shown())
		{
			if (o == ok)
			{
				for (std::size_t i = 0; i < _labels.size(); i++)
					_values[i] = s[i]->value();
				Fl::delete_widget(d);
				return 1;
			}
			else
			{
				if (o == cancel || o == d)
				{
					d->hide();
					Fl::delete_widget(d);
					return 0;
				}
			}
		}
	}
	return 0;
}

int Fle_Dialog::getItem(int _w, int _h, const char* _title, const char* _label, const std::vector<std::string>& _items, int& _selected_index)
{
	Fle_Dialog* d = new Fle_Dialog(_w, _h, _title, 58, 0, 0);
	d->callback(static_dialog_cb, d);
	d->setMargins(10, 10, 10, 10);

	Fle_HLayout* l = d->getCentralLayout()->addHLayout(25);

	l->begin();

	Fl_Choice* s;
	if (_label)
	{
		Fle_Box* b = new Fle_Box(0, 0, _w - 217, 25);
		b->color(fl_rgb_color(74, 84, 89));
		b->setText(_label);
		b->getFont()->setColor(fl_rgb_color(255, 255, 255));
		b->getFont()->setAlignment(FL_ALIGN_LEFT);

		s = new Fl_Choice(0, 0, 189, 25);
	}
	else
	{
		s = new Fl_Choice(0, 0, _w - 20, 25);
	}

	s->box(FL_FLAT_BOX);
	s->down_box(FL_FLAT_BOX);
	s->color(fl_rgb_color(74 + 20, 84 + 20, 89 + 20));
	s->color2(fl_rgb_color(253, 244, 191));
	s->textcolor(fl_rgb_color(255, 255, 255));
	s->textsize(12);
	for (std::size_t i = 0; i < _items.size(); i++)
		s->add(std::string(_items[i]).c_str());
	s->value(_selected_index);
	s->clear_visible_focus();
	if (_title) s->tooltip(_title);

	l->end();

	Fle_HLayoutLR* hl1 = d->getStatusBar()->addLayoutLR(23);
	hl1->setBackgroundColor(74, 84, 89);

	hl1->beginRight();

	Fle_Button* ok = new Fle_Button(0, 0, 90, 22, "OK");
	ok->color(fl_rgb_color(74, 84, 89));
	ok->selection_color(fl_rgb_color(74, 84, 89));
	ok->labelcolor(fl_rgb_color(255, 255, 255));
	ok->labelsize(12);
	d->setOkButton(ok);

	Fle_Button* cancel = new Fle_Button(0, 0, 90, 22, "Cancel");
	cancel->color(fl_rgb_color(74, 84, 89));
	cancel->selection_color(fl_rgb_color(74, 84, 89));
	cancel->labelcolor(fl_rgb_color(255, 255, 255));
	cancel->labelsize(12);
	d->setCancelButton(cancel);

	hl1->end();

	// set dialog's margins.
	d->getCentralLayout()->getCentralLayout()->setMargins(10, 10, 15, 0);
	// set statusbar's margins and height.
	d->getStatusBar()->getCentralLayout()->setMargins(10, 10, 10, 0);
	d->setStatusBarFixedHeight(58);

	d->resizable(0);
	d->hotspot(ok);
	d->set_modal();
	d->show();
	int X, Y, W, H;
	Fl::screen_work_area(X, Y, W, H);
	d->position(X + W / 2 - _w / 2, Y + H / 2 - _h / 2);

	while (d->shown())
	{
		Fl::wait();
		Fl_Widget* o;
		while (((o = Fl::readqueue())) && d->shown())
		{
			if (o == ok)
			{
				_selected_index = s->value();
				Fl::delete_widget(d);
				return 1;
			}
			else
			{
				if (o == cancel || o == d)
				{
					d->hide();
					Fl::delete_widget(d);
					return 0;
				}
			}
		}
	}
	return 0;
}

int Fle_Dialog::getText(int _w, int _h,
	const char* _title,
	std::string& _text,
	Fle_Font _text_prop,
	const char* _label,
	Fle_Font _label_prop)
{
	return Fle_Dialog::getText(_w, _h,
		_title,
		_text,
		_text_prop,
		_label,
		_label_prop,
		fl_rgb_color(74, 84, 89),
		fl_rgb_color(230, 230, 255));
}
int Fle_Dialog::getText(int _w, int _h,
const char* _title,
std::string& _text,
Fle_Font _text_prop)
{
	return Fle_Dialog::getText(_w, _h, 
		_title, 
		_text, 
		_text_prop,
		nullptr,
		Fle_Font(13, FL_WHITE, FL_ALIGN_LEFT, FL_HELVETICA_BOLD),
		fl_rgb_color(74, 84, 89),
		fl_rgb_color(230, 230, 255));
}


int Fle_Dialog::getText(int _w, int _h, 
	const char* _title, 
	std::string& _text,
	Fle_Font _text_prop,
	const char* _label, 
	Fle_Font _label_prop,
	Fl_Color _text_bkgrnd_color,
	Fl_Color _text_selection_color)
{
	Fle_Dialog* d = new Fle_Dialog(_w, _h, _title, 58, 0, 0);
	d->callback(static_dialog_cb, d);
	d->setMargins(10, 10, 10, 10);

	int lh = 74;

	if (_label)
	{
		d->begin();
		// create a label at the most left size.
		Fle_Box* b = new Fle_Box(0, 0, _w, 25);
		b->color(_text_bkgrnd_color);
		b->setText(_label);
		b->setFont(_label_prop);
		b->setFitToTextEnabled(true);

		Fle_Box* s = new Fle_Box(0, 0, _w, 1);
		s->box(FL_FLAT_BOX);
		s->color(fl_rgb_color(142, 142, 142));

		d->end();

		lh = 110;
	}

	Fle_HLayout* l = d->getCentralLayout()->addHLayout(_h - lh);
	l->begin();

	Fl_Multiline_Input* s = new Fl_Multiline_Input(0, 0, _w - 20, 25);
	s->box(FL_FLAT_BOX);
	s->color(_text_bkgrnd_color);
	s->selection_color(_text_selection_color);
	s->value(std::string(_text).c_str());
	s->align(_text_prop.getAlignment());
	s->textsize(_text_prop.getSize());
	s->textcolor(_text_prop.getColor());
	s->textfont(_text_prop.getFace());

	l->end();

	Fle_HLayoutLR* hl1 = d->getStatusBar()->addLayoutLR(23);
	hl1->setBackgroundColor(74, 84, 89);

	hl1->beginRight();

	Fle_Button* ok = new Fle_Button(0, 0, 90, 22, "OK");
	ok->color(fl_rgb_color(74, 84, 89));
	ok->selection_color(fl_rgb_color(74, 84, 89));
	ok->labelcolor(fl_rgb_color(255, 255, 255));
	ok->labelsize(12);
	d->setOkButton(ok);

	Fle_Button* cancel = new Fle_Button(0, 0, 90, 22, "Cancel");
	cancel->color(fl_rgb_color(74, 84, 89));
	cancel->selection_color(fl_rgb_color(74, 84, 89));
	cancel->labelcolor(fl_rgb_color(255, 255, 255));
	cancel->labelsize(12);
	d->setCancelButton(cancel);

	hl1->end();

	// set dialog's margins.
	d->getCentralLayout()->getCentralLayout()->setMargins(10, 10, 10, 0);
	// set statusbar's margins and height.
	d->getStatusBar()->getCentralLayout()->setMargins(10, 16, 10, 0);
	d->setStatusBarFixedHeight(58);

	d->resizable(0);
	d->hotspot(ok);
	d->set_modal();
	d->show();
	int X, Y, W, H;
	Fl::screen_work_area(X, Y, W, H);
	d->position(X + W / 2 - _w / 2, Y + H / 2 - _h / 2);

	while (d->shown())
	{
		Fl::wait();
		Fl_Widget* o;
		while (((o = Fl::readqueue())) && d->shown())
		{
			if (o == ok)
			{
				_text = s->value();
				Fl::delete_widget(d);
				return 1;
			}
			else
			{
				if (o == cancel || o == d)
				{
					d->hide();
					Fl::delete_widget(d);
					return 0;
				}
			}
		}
	}
	return 0;
}

int Fle_Dialog::openHelpDialog(
	int _w, int _h,
	const char* _title,
	const std::string& _html_text,
	Fle_Font _text_prop,
	const char* _label,
	Fle_Font _label_prop,
	Fl_Color _text_bkgrnd_color,
	Fl_Color _text_selection_color,
	Fl_Color _dialog_bkgrd_color)
{
	Fle_Dialog* d = new Fle_Dialog(_w, _h, _title, 58, 0, 0);
	d->callback(static_dialog_cb, d);
	d->setMargins(10, 10, 10, 10);
	d->setBackgroundColor(_dialog_bkgrd_color);

	int lh = 74;

	if (_label)
	{
		d->begin();
		// create a label at the most left size.
		Fle_Box* b = new Fle_Box(0, 0, _w, 25);
		b->color(_text_bkgrnd_color);
		b->setText(_label);
		b->setFont(_label_prop);
		b->setFitToTextEnabled(true);

		Fle_Box* s = new Fle_Box(0, 0, _w, 1);
		s->box(FL_FLAT_BOX);
		s->color(fl_rgb_color(142, 142, 142));

		d->end();

		lh = 110;
	}

	Fle_HLayout* l = d->getCentralLayout()->addHLayout(_h - lh);
	l->color(_dialog_bkgrd_color);
	l->begin();

	Fl_Help_View* s = new Fl_Help_View(0, 0, _w - 20, 25);
	s->box(FL_FLAT_BOX);
	s->color(_text_bkgrnd_color);
	s->selection_color(_text_selection_color);
	s->value(std::string(_html_text).c_str());
	s->align(_text_prop.getAlignment());
	s->textsize(_text_prop.getSize());
	s->textcolor(_text_prop.getColor());
	s->textfont(_text_prop.getFace());

	l->end();

	Fle_HLayoutLR* hl1 = d->getStatusBar()->addLayoutLR(23);
	hl1->setBackgroundColor(_dialog_bkgrd_color);

	hl1->beginRight();

	Fle_Button* ok = new Fle_Button(0, 0, 90, 22, "OK");
	ok->color(_dialog_bkgrd_color);
	ok->selection_color(_dialog_bkgrd_color);
	ok->labelcolor(fl_rgb_color(255, 255, 255));
	ok->labelsize(12);
	d->setOkButton(ok);

	hl1->end();

	// set dialog's margins.
	d->getCentralLayout()->getCentralLayout()->setMargins(10, 10, 10, 0);
	// set statusbar's margins and height.
	d->getStatusBar()->getCentralLayout()->setMargins(10, 16, 10, 0);
	d->setStatusBarFixedHeight(58);

	d->resizable(0);
	d->hotspot(ok);
	d->set_modal();
	d->show();
	int X, Y, W, H;
	Fl::screen_work_area(X, Y, W, H);
	d->position(X + W / 2 - _w / 2, Y + H / 2 - _h / 2);

	while (d->shown())
	{
		Fl::wait();
		Fl_Widget* o;
		while (((o = Fl::readqueue())) && d->shown())
		{
			if (o == ok)
			{
				Fl::delete_widget(d);
				return 1;
			}
			else
			{
				if (o == d)
				{
					d->hide();
					Fl::delete_widget(d);
					return 0;
				}
			}
		}
	}
	return 0;
}

int Fle_Dialog::ask(int _w, int _h, 			// width and height of the dialog window.
	const char* _title,  						// title of the dialog window.
	const std::string& _text,					// initial value and the returned value of the multi-line text box.
	const char* _1st_btn_text,
	const char* _2nd_btn_text,
	const char* _3rd_btn_text,
	Fle_Font _text_prop,						// _text properties
	Fl_Color _text_bkgrnd_color,				// background color of the text box.
	Fl_Color _text_selection_color)				// text selection color
{
	Fle_Dialog* d = new Fle_Dialog(_w, _h, _title, 58, 0, 0);
	d->callback(static_dialog_cb, d);
	d->setMargins(10, 10, 10, 10);

	int lh = 74;

	Fle_HLayout* l = d->getCentralLayout()->addHLayout(_h - lh);
	l->begin();

	Fl_Help_View* s = new Fl_Help_View(0, 0, _w - 20, 25);
	s->box(FL_FLAT_BOX);
	s->color(_text_bkgrnd_color);
	s->selection_color(_text_selection_color);
	s->value(std::string(_text).c_str());
	s->align(_text_prop.getAlignment());
	s->textsize(_text_prop.getSize());
	s->textcolor(_text_prop.getColor());
	s->textfont(_text_prop.getFace());

	l->end();

	Fle_HLayoutLR* hl1 = d->getStatusBar()->addLayoutLR(23);
	hl1->setBackgroundColor(74, 84, 89);

	hl1->beginRight();

	Fle_Button* yes = new Fle_Button(0, 0, 90, 22, _1st_btn_text);
	yes->color(fl_rgb_color(74, 84, 89));
	yes->selection_color(fl_rgb_color(74, 84, 89));
	yes->labelcolor(fl_rgb_color(255, 255, 255));
	yes->labelsize(12);
	d->setOkButton(yes);

	Fle_Button* no = nullptr;
	if (_2nd_btn_text)
	{
		no = new Fle_Button(0, 0, 90, 22, _2nd_btn_text);
		no->color(fl_rgb_color(74, 84, 89));
		no->selection_color(fl_rgb_color(74, 84, 89));
		no->labelcolor(fl_rgb_color(255, 255, 255));
		no->labelsize(12);
		d->setCancelButton(no);
	}

	Fle_Button* cancel = nullptr;
	if (_3rd_btn_text)
	{
		cancel = new Fle_Button(0, 0, 90, 22, _3rd_btn_text);
		cancel->color(fl_rgb_color(74, 84, 89));
		cancel->selection_color(fl_rgb_color(74, 84, 89));
		cancel->labelcolor(fl_rgb_color(255, 255, 255));
		cancel->labelsize(12);
		d->setCancelButton(no);
	}

	hl1->end();

	// set dialog's margins.
	d->getCentralLayout()->getCentralLayout()->setMargins(10, 10, 10, 0);
	// set statusbar's margins and height.
	d->getStatusBar()->getCentralLayout()->setMargins(10, 16, 10, 0);
	d->setStatusBarFixedHeight(58);

	d->resizable(0);
	d->hotspot(yes);
	d->set_modal();
	d->show();
	int X, Y, W, H;
	Fl::screen_work_area(X, Y, W, H);
	d->position(X + W / 2 - _w / 2, Y + H / 2 - _h / 2);
	fl_beep();

	while (d->shown())
	{
		Fl::wait();
		Fl_Widget* o;
		while (((o = Fl::readqueue())) && d->shown())
		{
			if (o == yes)
			{
				Fl::delete_widget(d);
				return 1;
			}
			else
			{
				if (o == no || o == d)
				{
					d->hide();
					Fl::delete_widget(d);
					return 0;
				}
				else if (o == cancel)
				{
					d->hide();
					Fl::delete_widget(d);
					return 2;
				}
			}
		}
	}
	return 0;
}
int Fle_Dialog::ask(int _w, int _h, 			// width and height of the dialog window.
	const char* _title,  						// title of the dialog window.
	const std::string& _text,					// initial value and the returned value of the multi-line text box.
	const char* _1st_btn_text,
	const char* _2nd_btn_text)
{
	return ask(_w, _h, _title, _text, _1st_btn_text, _2nd_btn_text, nullptr);
}
int Fle_Dialog::ask(
	const char* _title,  						// title of the dialog window.
	const std::string& _text,
	const char* _1st_btn_text,			// first button text.
	const char* _2nd_btn_text,			// 2nd button text.
	const char* _3rd_btn_text			// 3rd button text.
	)
{
	return ask(400, 150, _title, _text, _1st_btn_text, _2nd_btn_text, _3rd_btn_text);
}

int Fle_Dialog::ask(
	const char* _title,  						// title of the dialog window.
	const std::string& _text,
	const char* _1st_btn_text,			// first button text.
	const char* _2nd_btn_text			// 2nd button text.
	)
{
	return ask(_title, _text, _1st_btn_text, _2nd_btn_text, nullptr);
}
void Fle_Dialog::Message(
	const char* _title,  				// title of the dialog window.
	const std::string& _text,
	const char* _btn_text				// first button text.
)
{
	ask(458, 132, _title, _text, _btn_text,  nullptr, nullptr);
}

int Fle_Dialog::exec()
{
	hotspot(p_ok);
	set_modal();
	show();

	while (visible())
	{
		Fl::wait();
		Fl_Widget* o;
		while (((o = Fl::readqueue())) && visible())
		{
			if (o == p_ok)
			{
				Fl::delete_widget(this);
				return 1;
			}
			else
			{
				if (o == p_cancel || o == this)
				{
					Fl::delete_widget(this);
					return 0;
				}
			}
		}
	}
	return 0;
}

int Fle_Dialog::browse(int _w, int _h, const char* _title, const char* _label, const char* _filters, std::string& _value)
{
	Fle_Dialog* d = new Fle_Dialog(_w, _h, _title, 58, 0, 0);
	d->callback(static_dialog_cb, d);
	d->setMargins(10, 10, 10, 10);

	Fle_HLayout* l = d->getCentralLayout()->addHLayout(25);

	l->begin();

	Fle_InputWidget* s = new Fle_InputWidget(0, 0, _w - 20, 25, _label);
	s->box(FL_BORDER_BOX);
	s->align(FL_ALIGN_LEFT);
	s->setRightClickPopupColor(fl_rgb_color(74, 84, 89));
	s->setRightClickPopupTextColor(fl_rgb_color(255, 255, 255));
	s->color(fl_rgb_color(74, 84, 89));
	s->textcolor(fl_rgb_color(255, 255, 255));
	s->textsize(12);
	if(!_value.empty())
		s->value(std::string(_value).c_str());

	l->end();

	Fle_HLayoutLR* hl1 = d->getStatusBar()->addLayoutLR(23);
	hl1->setBackgroundColor(74, 84, 89);

	hl1->beginRight();

	Fle_Button* ok = new Fle_Button(0, 0, 90, 22, "Ok");
	ok->color(fl_rgb_color(74, 84, 89));
	ok->selection_color(fl_rgb_color(74, 84, 89));
	ok->labelcolor(fl_rgb_color(255, 255, 255));
	ok->labelsize(12);
	d->setOkButton(ok);

	Fle_Button* cancel = new Fle_Button(0, 0, 90, 22, "Cancel");
	cancel->color(fl_rgb_color(74, 84, 89));
	cancel->selection_color(fl_rgb_color(74, 84, 89));
	cancel->labelcolor(fl_rgb_color(255, 255, 255));
	cancel->labelsize(12);
	d->setCancelButton(cancel);

	hl1->end();

	// set dialog's margins.
	d->getCentralLayout()->getCentralLayout()->setMargins(10, 10, 15, 0);
	// set statusbar's margins and height.
	d->getStatusBar()->getCentralLayout()->setMargins(10, 10, 10, 0);
	d->setStatusBarFixedHeight(58);

	d->resizable(0);
	d->hotspot(ok);
	d->set_modal();
	d->show();
	int X, Y, W, H;
	Fl::screen_work_area(X, Y, W, H);
	d->position(X + W / 2 - _w / 2, Y + H / 2 - _h / 2);

	while (d->shown())
	{
		Fl::wait();
		Fl_Widget* o;
		while (((o = Fl::readqueue())) && d->shown())
		{
			if (o == ok)
			{
				_value = std::string(s->value());
				if (_value.empty())
				{
					Fle_FileDialog dlg;
					int n = dlg.browsSingleFile(_filters, _title);
					if (n > 0)
						_value = dlg.getPath(0);
				}
				Fl::delete_widget(d);
				return 1;
			}
			else
			{
				if (o == cancel || o == d)
				{
					d->hide();
					Fl::delete_widget(d);
					return 0;
				}
			}
		}
	}
	return 0;
}
