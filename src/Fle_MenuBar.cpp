/*********************************************************************************
created:	2017/01/28   06:54AM
filename: 	Fle_MenuBar.h
file base:	Fle_MenuBar
file ext:	h
author:		Furqan Ullah (Post-doc, Ph.D.)
website:    http://real3d.pk
CopyRight:	All Rights Reserved

purpose:	A customized menu bar with fixed size and position compatibility.

/**********************************************************************************
FL-ESSENTIALS (FLE) - FLTK Utility Widgets
Copyright (C) 2014-2019 REAL3D

This file and its content is protected by a software license.
You should have received a copy of this license with this file.
If not, please contact Dr. Furqan Ullah immediately:
**********************************************************************************/

#include <FLE/Fle_MenuBar.h>

#include <FL/fl_draw.H>
#include <FL/Fl.H>

using namespace R3D;

Fle_MenuBar::Fle_MenuBar(int _x, int _y, int _w, int _h, const char* _text) :
Fl_Menu_Bar(_x, _y, _w, _h, _text),
m_menubox(Fl_Boxtype::FL_FLAT_BOX),
p_rightclick_popup_items(nullptr),
p_rightclick_popup_item_cb(nullptr),
p_rightclick_popup_cb_data(nullptr),
m_is_popup(true)
{
	// Qt colors
	//setMenuBarColor(255, 255, 255);
	//setMenuBarItemsColor(240, 240, 240);
	//setSelectionColor(144, 200, 246);
	// MS VS2013 colors
	setMenuBarColor(204, 209, 223);
	setMenuBarItemsColor(fl_rgb_color(224, 230, 245));
	setSelectionColor(253, 244, 191);
	setRightClickPopupColor(fl_rgb_color(234, 240, 255));
	setRightClickPopupTextColor(fl_rgb_color(1, 1, 1));
	box(Fl_Boxtype::FL_FLAT_BOX);
	down_box(Fl_Boxtype::FL_FLAT_BOX);
	textsize(12);
	textfont(FL_HELVETICA);
	align(FL_ALIGN_WRAP | FL_ALIGN_CENTER | FL_ALIGN_TEXT_OVER_IMAGE | FL_ALIGN_CLIP);
}

Fle_MenuBar::~Fle_MenuBar()
{
}

void Fle_MenuBar::draw()
{
	draw(Fl_Menu_Bar::x(), Fl_Menu_Bar::y(), Fl_Menu_Bar::w(), Fl_Menu_Bar::h());
}
void Fle_MenuBar::draw(int _x, int _y, int _w, int _h)
{
	draw_box(m_menubox, _x, _y, _w, _h, m_menucolor);
	if (!menu() || !menu()->text) return;
	const Fl_Menu_Item* m;
	int X = _x + 6;
	for (m = menu()->first(); m->text; m = m->next())
	{
		int W = m->measure(0, this) + 16;
		m->draw(X, _y, W, _h, this);
		X += W;
		if (m->flags & FL_MENU_DIVIDER)
		{
			int y1 = _y + Fl::box_dy(box());
			int y2 = y1 + _h - Fl::box_dh(box()) - 1;

			// draw a vertical divider between menus.
			fl_color(FL_DARK3);
			fl_yxline(X - 6, y1, y2);
			fl_color(FL_LIGHT3);
			fl_yxline(X - 5, y1, y2);
		}
	}
}

int Fle_MenuBar::handle(int _e)
{
	switch (_e) 
	{
	case FL_PUSH:
		if (Fl::event_button() == FL_RIGHT_MOUSE) 
		{
			if (p_rightclick_popup_items && m_is_popup)
			{
				Fl_Menu_Button mb(Fl::event_x(), Fl::event_y(), 0, 0);
				mb.box(FL_FLAT_BOX);
				mb.down_box(FL_FLAT_BOX);
				//mb.color(fl_rgb_color(242, 244, 254));
				mb.color(m_rclick_pop_clr);
				mb.textcolor(m_rclick_pop_tclr);
				mb.color2(fl_rgb_color(253, 244, 191));
				mb.labelsize(12);
				mb.textsize(12);
				mb.clear_visible_focus();

				mb.menu(p_rightclick_popup_items);
				if (p_rightclick_popup_item_cb && p_rightclick_popup_cb_data)
					mb.callback(p_rightclick_popup_item_cb, p_rightclick_popup_cb_data);
				mb.popup();
			}
			return 1;          // tells caller we handled this event
		}
		break;

	case FL_RELEASE:
		if (Fl::event_button() == FL_RIGHT_MOUSE) 
			return 1;          // tells caller we handled this event
		break;

	default:
		break;
	}
	return Fl_Menu_Bar::handle(_e);
}

void Fle_MenuBar::setMenuBarItemsColor(uchar _red, uchar _green, uchar _blue)
{
	Fl_Menu_Bar::color(fl_rgb_color(_red, _green, _blue));
}
void Fle_MenuBar::setMenuBarItemsColor(Fl_Color _color)
{
	Fl_Menu_Bar::color(_color);
}
Fl_Color Fle_MenuBar::getMenuBarItemsColor() const
{
	return Fl_Menu_Bar::color();
}
void Fle_MenuBar::setMenuBarColor(uchar _red, uchar _green, uchar _blue)
{
	m_menucolor = fl_rgb_color(_red, _green, _blue);
	redraw();
}
Fl_Color Fle_MenuBar::getMenuBarColor() const
{
	return m_menucolor;
}
void Fle_MenuBar::setSelectionColor(uchar _red, uchar _green, uchar _blue)
{
	Fl_Menu_Bar::selection_color(fl_rgb_color(_red, _green, _blue));
}
void Fle_MenuBar::setSelectionColor(Fl_Color _color)
{
	Fl_Menu_Bar::selection_color(_color);
}
Fl_Color Fle_MenuBar::getSelectionColor() const
{
	return Fl_Menu_Bar::selection_color();
	//uchar r = (c & 0xFF000000) >> 24;
	//uchar g = (c & 0x00FF0000) >> 16;
	//uchar b = (c & 0x0000FF00) >> 8;
	//return cv::Vec3b(r, g, b);
}

bool Fle_MenuBar::setRadioItemOn(const char* _item_name, bool _state)
{
	Fl_Menu_Item* m = (Fl_Menu_Item*)find_item(_item_name);
	if (m)
	{
		if (_state) m->setonly();
		else m->clear();

		return true;
	}
	return false;
}
bool Fle_MenuBar::isRadioItemOn(const char* _item_name)
{
	return getItemState(_item_name);
}
bool Fle_MenuBar::setRadioItemOn(Fl_Callback* _cb, bool _state)
{
	Fl_Menu_Item* m = (Fl_Menu_Item*)find_item(_cb);
	if (m)
	{
		if (_state) m->setonly();
		else m->clear();

		return true;
	}
	return false;
}
bool Fle_MenuBar::isRadioItemOn(Fl_Callback* _cb)
{
	return getItemState(_cb);
}

bool Fle_MenuBar::setItemState(const char* _item_name, bool _state)
{
	Fl_Menu_Item* m = (Fl_Menu_Item*)find_item(_item_name);
	if (m)
	{
		if (_state) m->set();
		else m->clear();

		return true;
	}
	return false;
}
bool Fle_MenuBar::getItemState(const char* _item_name)
{
	Fl_Menu_Item* m = (Fl_Menu_Item*)find_item(_item_name);
	if (m)
	{
		if (m->value() > 0)
			return true;
	}
	return false;
}
bool Fle_MenuBar::setItemState(Fl_Callback* _cb, bool _state)
{
	Fl_Menu_Item* m = (Fl_Menu_Item*)find_item(_cb);
	if (m)
	{
		if (_state) m->set();
		else m->clear();
		
		return true;
	}
	return false;
}
bool Fle_MenuBar::getItemState(Fl_Callback* _cb)
{
	Fl_Menu_Item* m = (Fl_Menu_Item*)find_item(_cb);
	if (m)
	{
		if (m->value() > 0)
			return true;
	}
	return false;
}

bool Fle_MenuBar::setItemActive(const char* _item_name, bool _state)
{
	Fl_Menu_Item* m = (Fl_Menu_Item*)find_item(_item_name);
	if (m)
	{
		if (_state) m->activate();
		else m->deactivate();

		return true;
	}
	return false;
}
bool Fle_MenuBar::isItemActive(const char* _item_name)
{
	Fl_Menu_Item* m = (Fl_Menu_Item*)find_item(_item_name);
	if (m)
	{
		if (m->active())
			return true;
	}
	return false;
}
bool Fle_MenuBar::setItemActive(Fl_Callback* _cb, bool _state)
{
	Fl_Menu_Item* m = (Fl_Menu_Item*)find_item(_cb);
	if (m)
	{
		if (_state) m->activate();
		else m->deactivate();

		return true;
	}
	return false;
}
bool Fle_MenuBar::isItemActive(Fl_Callback* _cb)
{
	Fl_Menu_Item* m = (Fl_Menu_Item*)find_item(_cb);
	if (m)
	{
		if (m->active())
			return true;
	}
	return false;
}
