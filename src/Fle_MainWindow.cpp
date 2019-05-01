/*********************************************************************************
created:	2017/01/29   05:58AM
filename: 	Fle_MainWindow.h
file base:	Fle_MainWindow
file ext:	h
author:		Furqan Ullah (Post-doc, Ph.D.)
website:    http://real3d.pk
CopyRight:	All Rights Reserved

purpose:	Main window class with menu, tool, and status bars.

/**********************************************************************************
FL-ESSENTIALS (FLE) - FLTK Utility Widgets
Copyright (C) 2014-2019 REAL3D

This file and its content is protected by a software license.
You should have received a copy of this license with this file.
If not, please contact Dr. Furqan Ullah immediately:
**********************************************************************************/

#include <FLE/Fle_MainWindow.h>
#include <FLE/Fle_MessageBox.h>
#include <FLE/Fle_WindowsUtil.h>

#include <FL/fl_draw.H>

#include <iostream>

using namespace R3D;

static Fl_Menu_Item rightClickMenuItems[] = 
{
	{ "\tMenuBar\t",	FL_CTRL + FL_SHIFT + 'm', 0, (void *)1, FL_MENU_TOGGLE | FL_MENU_VALUE/*, FL_BOLD + FL_ITALIC, 14*/ },
	{ "\tTopBar\t",		0, 0, (void*)2, FL_MENU_TOGGLE | FL_MENU_VALUE },
	{ "\tLeftBar\t",	0, 0, (void*)3, FL_MENU_TOGGLE | FL_MENU_VALUE },
	{ "\tRightBar\t",	0, 0, (void*)4, FL_MENU_TOGGLE | FL_MENU_VALUE },
	{ "\tStatusBar\t",	0, 0, (void*)5, FL_MENU_TOGGLE | FL_MENU_VALUE },
	{ 0 }
};

Fle_MainWindow::Fle_MainWindow(int _x, int _y, int _w, int _h, const char* _title, int _icon_index) :
Fle_Window(_x, _y, _w, _h, _title, _icon_index),
m_leftmargin(0),
m_topmargin(0),
m_rightmargin(0),
m_bottommargin(0)
{
	int mb_size = 25;
	int sb_size = 22;
	int tb_size = 25;
	int left_tb_size = 25;
	int right_tb_size = 25;
	int gap = 5;

	setBox(nullptr);	// remove the box from the window.

	Fle_Window::begin();
	{
		p_centralarea = new Fle_Window(left_tb_size + gap, mb_size + tb_size + gap, _w - left_tb_size - right_tb_size - gap - gap, _h - mb_size - tb_size - sb_size - gap - gap, _title, _icon_index);
		p_centralarea->end();

		p_toptoolbar = new Fle_ToolBar(0, mb_size, _w, tb_size);
		p_toptoolbar->box(FL_BORDER_FRAME);
		p_toptoolbar->end();

		p_lefttoolbar = new Fle_ToolBar(0, mb_size + tb_size, left_tb_size, _h - mb_size - tb_size - sb_size);
		p_lefttoolbar->setMargins(4, 4, 4, 4);
		p_lefttoolbar->getCentralLayout()->getTopLayout()->setSpacing(10);
		p_lefttoolbar->end();
		p_righttoolbar = new Fle_ToolBar(_w - right_tb_size, mb_size + tb_size, right_tb_size, _h - mb_size - tb_size - sb_size);
		p_righttoolbar->setMargins(4, 4, 4, 4);
		p_righttoolbar->getCentralLayout()->getTopLayout()->setSpacing(10);
		p_righttoolbar->end();

		p_statusbar = new Fle_StatusBar(0, _h - sb_size, _w, sb_size);
		p_statusbar->end();

		p_menubar = new Fle_MenuBar(-1, 0, _w + 2, mb_size, label());	// little expanded to hide the left and right borders.
		p_menubar->setRightClickPopupCallback(rightClickMenuItems, rightClickMenuItem_cb, (void*)this);

		p_menubar->hide();
		p_statusbar->hide();
		p_toptoolbar->hide();
		p_lefttoolbar->hide();
		p_righttoolbar->hide();
	}
	Fle_Window::end();

	Fle_Window::setBackgroundColor(41, 57, 85);
	color(fl_rgb_color(41, 57, 85));
	user_data(static_cast<void*>(this));
	resizable(p_centralarea);
	size_range(100, 100);
}

Fle_MainWindow::Fle_MainWindow(int _w, int _h, const char* _title, int _icon_index) :
Fle_Window(0, 0, _w, _h, _title, _icon_index),
m_leftmargin(0),
m_topmargin(0),
m_rightmargin(0),
m_bottommargin(0)
{
	int mb_size = 25;
	int sb_size = 22;
	int tb_size = 25;
	int left_tb_size = 25;
	int right_tb_size = 25;
	int gap = 5;

	setBox(nullptr);	// remove the box from the window.

	Fle_Window::begin();
	{
		p_centralarea = new Fle_Window(left_tb_size + gap, mb_size + tb_size + gap, _w - left_tb_size - right_tb_size - gap - gap, _h - mb_size - tb_size - sb_size - gap - gap, _title, _icon_index);
		p_centralarea->end();

		p_toptoolbar = new Fle_ToolBar(0, mb_size, _w, tb_size);
		p_toptoolbar->box(FL_BORDER_FRAME);
		p_toptoolbar->end();

		p_lefttoolbar = new Fle_ToolBar(0, mb_size + tb_size, left_tb_size, _h - mb_size - tb_size - sb_size);
		p_lefttoolbar->setMargins(4, 4, 4, 4);
		p_lefttoolbar->getCentralLayout()->getTopLayout()->setSpacing(10);
		p_lefttoolbar->end();
		p_righttoolbar = new Fle_ToolBar(_w - right_tb_size, mb_size + tb_size, right_tb_size, _h - mb_size - tb_size - sb_size);
		p_righttoolbar->setMargins(4, 4, 4, 4);
		p_righttoolbar->getCentralLayout()->getTopLayout()->setSpacing(10);
		p_righttoolbar->end();

		p_statusbar = new Fle_StatusBar(0, _h - sb_size, _w, sb_size);
		p_statusbar->end();

		p_menubar = new Fle_MenuBar(-1, 0, _w + 2, mb_size, label());	// little expanded to hide the left and right borders.
		p_menubar->setRightClickPopupCallback(rightClickMenuItems, rightClickMenuItem_cb, (void*)this);

		p_menubar->hide();
		p_statusbar->hide();
		p_toptoolbar->hide();
		p_lefttoolbar->hide();
		p_righttoolbar->hide();
	}
	Fle_Window::end();

	Fle_Window::setBackgroundColor(41, 57, 85);
	color(fl_rgb_color(41, 57, 85));
	user_data(static_cast<void*>(this));
	resizable(p_centralarea);
	size_range(100, 100);

	// positioned at center of the screen.
	int X, Y, W, H;
	Fl::screen_work_area(X, Y, W, H);
	position(X + W / 2 - _w / 2, Y + H / 2 - _h / 2);
}

Fle_MainWindow::~Fle_MainWindow()
{
}

void Fle_MainWindow::begin()
{
	p_centralarea->begin();
}
void Fle_MainWindow::end()
{
	p_centralarea->end();
	Fle_Window::end();
}
void Fle_MainWindow::beginTopArea()
{
	Fle_Window::begin();
}
void Fle_MainWindow::endTopArea()
{
	Fle_Window::end();
}

void Fle_MainWindow::resize(int _x, int _y, int _w, int _h)
{
	Fle_Window::resize(_x, _y, _w, _h);
	updateContents();
}

void Fle_MainWindow::size(int _w, int _h)
{
	resize(x(), y(), _w, _h);
}

void Fle_MainWindow::redraw()
{
	p_centralarea->redraw();
	Fle_Window::redraw();
}
void Fle_MainWindow::update()
{
	redraw();
}
void Fle_MainWindow::draw()
{
	Fle_Window::draw();
}

int Fle_MainWindow::keyPressEvent(int _key)
{
	if (_key == 'm')
	{
		if (Fl::event_state(FL_CTRL) && Fl::event_state(FL_SHIFT))	// if CTRL+SHIFT key is pressed along with m
		{
			toggleMenuBar();
			return 1;
		}
	}
	return 0;
}

void Fle_MainWindow::rightClickMenuItem_cb(Fl_Widget* _w, void* _p)
{
	Fl_Menu_* menu = static_cast<Fl_Menu_*>(_w);
	if (!menu) return;
	Fle_MainWindow* win = static_cast<Fle_MainWindow*>(_p);
	if (!win) return;
	const Fl_Menu_Item* m = menu->mvalue();
	if (!m) return;

	std::string l(m->label());
	if (l == std::string("\tMenuBar\t"))
		win->toggleMenuBar();
	else if (l == std::string("\tTopBar\t"))
		win->toggleTopToolBar();
	else if (l == std::string("\tLeftBar\t"))
		win->toggleLeftToolBar();
	else if (l == std::string("\tRightBar\t"))
		win->toggleRightToolBar();
	else if (l == std::string("\tStatusBar\t"))
		win->toggleStatusBar();
}

void Fle_MainWindow::toggleMenuBar()
{
	if (p_menubar->visible()) p_menubar->hide();
	else p_menubar->show();
	size(w(), h());
	redraw();
}
void Fle_MainWindow::toggleTopToolBar()
{
	if (p_toptoolbar->visible()) p_toptoolbar->hide();
	else p_toptoolbar->show();
	size(w(), h());
	redraw();
}
void Fle_MainWindow::toggleStatusBar()
{
	if (p_statusbar->visible()) p_statusbar->hide();
	else p_statusbar->show();
	size(w(), h());
	redraw();
}
void Fle_MainWindow::toggleLeftToolBar()
{
	if (p_lefttoolbar->visible()) p_lefttoolbar->hide();
	else p_lefttoolbar->show();
	size(w(), h());
	redraw();
}
void Fle_MainWindow::toggleRightToolBar()
{
	if (p_righttoolbar->visible()) p_righttoolbar->hide();
	else p_righttoolbar->show();
	size(w(), h());
	redraw();
}

void Fle_MainWindow::toggleMenuBar_cb(Fl_Widget* _w, void* _p)
{
	Fle_MainWindow* win = static_cast<Fle_MainWindow*>(_p);
	if(win) win->toggleMenuBar();
}
void Fle_MainWindow::toggleTopToolBar_cb(Fl_Widget* _w, void* _p)
{
	Fle_MainWindow* win = static_cast<Fle_MainWindow*>(_p);
	if (win) win->toggleTopToolBar();
}
void Fle_MainWindow::toggleStatus_cb(Fl_Widget* _w, void* _p)
{
	Fle_MainWindow* win = static_cast<Fle_MainWindow*>(_p);
	if (win) win->toggleStatusBar();
}
void Fle_MainWindow::toggleLeftToolBar_cb(Fl_Widget* _w, void* _p)
{
	Fle_MainWindow* win = static_cast<Fle_MainWindow*>(_p);
	if (win) win->toggleLeftToolBar();
}
void Fle_MainWindow::toggleRightToolBar_cb(Fl_Widget* _w, void* _p)
{
	Fle_MainWindow* win = static_cast<Fle_MainWindow*>(_p);
	if (win) win->toggleRightToolBar();
}

void Fle_MainWindow::updateContents()
{
	// adjust the central area while resizing the window.
	// 31 combination of visible or not-visible widgets that I have fixed.
	// It was hella time consuming but it was really important for better visualization and convenience. 
	// Now all toolbars, menubar, and statusbar are
	// synchronized to each other.
	int gap = 0;

	unsigned int m = p_menubar->visible();
	unsigned int t = p_toptoolbar->visible();
	unsigned int s = p_statusbar->visible();
	unsigned int l = p_lefttoolbar->visible();
	unsigned int r = p_righttoolbar->visible();

	int lw = p_lefttoolbar->w();
	int lh = p_lefttoolbar->h();

	int rw = p_righttoolbar->w();
	int rh = p_righttoolbar->h();

	int tw = p_toptoolbar->w();
	int th = p_toptoolbar->h();

	int mw = p_menubar->w();
	int mh = p_menubar->h();

	int sw = p_statusbar->w();
	int sh = p_statusbar->h();

	// if all widgets are visible.
	if (m && t && s && l && r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + lw + gap,
			m_topmargin + mh + th + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - lw - rw - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - mh - th - sh - gap - gap
			);
	}
	// if only menubar is visible.
	else if (m && !t && !s && !l && !r)
		p_centralarea->resize(
		0 + m_leftmargin + gap,
		m_topmargin + mh + gap,
		Fle_Window::w() - m_rightmargin - m_leftmargin - gap - gap,
		Fle_Window::h() - m_bottommargin - m_topmargin - mh - gap - gap
		);
	// if menubar and top toolbar are visible.
	else if (m && t && !s && !l && !r)
		p_centralarea->resize(
		0 + m_leftmargin + gap,
		m_topmargin + mh + th + gap,
		Fle_Window::w() - m_rightmargin - m_leftmargin - gap - gap,
		Fle_Window::h() - m_bottommargin - m_topmargin - mh - th - gap - gap
		);
	// if menubar, top toolbar, and statusbar are visible.
	else if (m && t && s && l && !r)
		p_centralarea->resize(
		0 + m_leftmargin + lw + gap,
		m_topmargin + mh + th + gap,
		Fle_Window::w() - m_rightmargin - m_leftmargin - lw - gap - gap,
		Fle_Window::h() - m_bottommargin - m_topmargin - mh - th - sh - gap - gap
		);


	// if top toolbar and statusbar are visible.
	else if (!m && t && s && !l && !r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + gap,
			m_topmargin + th + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - th - sh - gap - gap
			);
	}
	// if top toolbar and left toolbar are visible.
	else if (!m && t && !s && l && !r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + lw + gap,
			m_topmargin + th + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - lw - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - th - gap - gap
			);
	}
	// if top toolbar and right toolbar are visible.
	else if (!m && t && !s && !l && r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + gap,
			m_topmargin + th + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - rw - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - th - gap - gap
			);
	}

	// only menu
	// if statusbar and left toolbar are visible.
	else if (!m && !t && s && l && !r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + lw + gap,
			m_topmargin + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - lw - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - sh - gap - gap
			);
	}
	// if statusbar and right toolbar are visible.
	else if (!m && !t && s && !l && r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + gap,
			m_topmargin + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - rw - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - sh - gap - gap
			);
	}


	// if left and right toolbars are visible.
	else if (!m && !t && !s && l && r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + lw + gap,
			m_topmargin + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - lw - rw - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - gap - gap
			);
	}

	// only toolbar
	// if only top toolbar is visible.
	else if (!m && t && !s && !l && !r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + gap,
			m_topmargin + th + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - th - gap - gap
			);
	}
	// if only statusbar is visible.
	else if (!m && !t && s && !l && !r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + gap,
			m_topmargin + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - sh - gap - gap
			);
	}
	// if only left toolbar is visible.
	else if (!m && !t && !s && l && !r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + lw + gap,
			m_topmargin + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - lw - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - gap - gap
			);
	}
	// if only right toolbar is visible.
	else if (!m && !t && !s && !l && r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + gap,
			m_topmargin + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - rw - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - gap - gap
			);
	}

	// only menu
	// if menubar and statusbar are visible.
	else if (m && !t && s && !l && !r)
		p_centralarea->resize(
		0 + m_leftmargin + gap,
		m_topmargin + mh + gap,
		Fle_Window::w() - m_rightmargin - m_leftmargin - gap - gap,
		Fle_Window::h() - m_bottommargin - m_topmargin - mh - sh - gap - gap
		);
	// if menubar and left toolbar are visible.
	else if (m && !t && !s && l && !r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + lw + gap,
			m_topmargin + mh + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - lw - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - mh - gap - gap
			);
	}
	// if menubar and right toolbar are visible.
	else if (m && !t && !s && !l && r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + gap,
			m_topmargin + mh + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - rw - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - mh - gap - gap
			);
	}

	// if all widgets are invisible.
	else if (!m && !t && !s && !l && !r)
		p_centralarea->resize(
		0 + m_leftmargin + gap,
		m_topmargin + gap,
		Fle_Window::w() - m_rightmargin - m_leftmargin - gap - gap,
		Fle_Window::h() - m_bottommargin - m_topmargin - gap - gap
		);

	// if toolbar, statusbar, left toolbar, and right toolbars are visible.
	else if (!m && t && s && l && r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + lw + gap,
			m_topmargin + th + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - lw - rw - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - th - sh - gap - gap
			);
	}
	else if (m && !t && s && l && r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + lw + gap,
			m_topmargin + mh + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - lw - rw - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - mh - sh - gap - gap
			);

	}
	else if (m && t && !s && l && r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + lw + gap,
			m_topmargin + mh + th + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - lw - rw - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - mh - th - gap - gap
			);

	}
	else if (m && t && s && !l && r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + gap,
			m_topmargin + mh + th + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - rw - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - mh - th - sh - gap - gap
			);
	}

	// tool bar with others
	else if (!m && !t && s && l && r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + lw + gap,
			m_topmargin + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - lw - rw - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - sh - gap - gap
			);
	}
	else if (m && !t && s && !l && r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + gap,
			m_topmargin + mh + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - rw - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - mh - sh - gap - gap
			);
	}
	else if (m && !t && s && l && !r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + lw + gap,
			m_topmargin + mh + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - lw - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - mh - sh - gap - gap
			);
	}


	// left bar with others
	else if (!m && t && s && !l && r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + gap,
			m_topmargin + th + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - rw - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - th - sh - gap - gap
			);
	}
	else if (m && t && s && !l && !r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + gap,
			m_topmargin + mh + th + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - mh - th - sh - gap - gap
			);
	}
	else if (!m && t && s && l && !r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + lw + gap,
			m_topmargin + th + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - lw - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - th - sh - gap - gap
			);
	}



	// status bar with others
	else if (!m && t && !s && l && r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + lw + gap,
			m_topmargin + th + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - lw - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - th - gap - gap
			);
	}
	else if (m && !t && !s && l && r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + lw + gap,
			m_topmargin + mh + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - lw - rw - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - mh - gap - gap
			);
	}
	else if (m && t && !s && !l && r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + gap,
			m_topmargin + mh + th + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - rw - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - mh - th - gap - gap
			);
	}
	else if (m && t && !s && l && !r)
	{
		p_centralarea->resize(
			0 + m_leftmargin + lw + gap,
			m_topmargin + mh + th + gap,
			Fle_Window::w() - m_rightmargin - m_leftmargin - lw - gap - gap,
			Fle_Window::h() - m_bottommargin - m_topmargin - mh - th - gap - gap
			);
	}

	if (p_menubar->visible()) 
		p_toptoolbar->position(0, p_menubar->h());
	else  
		p_toptoolbar->position(0, 0);

	if (p_statusbar->visible()) 
		p_statusbar->position(0, h() - p_statusbar->h());

	p_lefttoolbar->resize(0, p_centralarea->y(), lw, p_centralarea->h());
	p_righttoolbar->resize(p_centralarea->x() + p_centralarea->w() + gap + m_rightmargin, p_centralarea->y(), rw, p_centralarea->h());
}

void Fle_MainWindow::setBackgroundColor(uchar _red, uchar _green, uchar _blue)
{
	Fle_Window::setBackgroundColor(_red, _green, _blue);
	p_centralarea->setBackgroundColor(_red, _green, _blue);
}
void Fle_MainWindow::setBackgroundColor(Fl_Color _color)
{
	Fle_Window::setBackgroundColor(_color);
	p_centralarea->setBackgroundColor(_color);
}