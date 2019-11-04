/* B.SEQuencer
 * MIDI Step Sequencer LV2 Plugin
 *
 * Copyright (C) 2018, 2019  Sven Jähnichen
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef REDOBUTTON_HPP_
#define REDOBUTTON_HPP_

#include <cmath>
#include "BWidgets/Button.hpp"
#include "BWidgets/Label.hpp"

class RedoButton : public BWidgets::Button
{
protected:
        BWidgets::Label focusLabel;

public:
        RedoButton () : RedoButton (0.0, 0.0, BWIDGETS_DEFAULT_BUTTON_WIDTH, BWIDGETS_DEFAULT_BUTTON_HEIGHT, "button", 0.0) {}
	RedoButton (const double x, const double y, const double width, const double height, const std::string& name, double defaultValue = 0.0) :
                Button (x, y, width, height, name, defaultValue),
                focusLabel (0, 0, 40, 20, name + "/focus/label", "Redo")
        {
                focusWidget = new BWidgets::FocusWidget (this, name + "/focus");
        	if (focusWidget)
        	{
        		focusWidget->add (focusLabel);
        		focusWidget->resize ();
        	}
        }

        virtual void applyTheme (BStyles::Theme& theme, const std::string& name) override
	{
		Button::applyTheme (theme, name);

		if (focusWidget)
		{
			focusWidget->applyTheme (theme, name + "/focus");

			std::vector<BWidgets::Widget*> childs = focusWidget->getChildren ();
			for (BWidgets::Widget* c : childs)
			{
				if (c)
				{
					c->applyTheme (theme, name + "/focus/label");
					c->resize ();
				}
			}

			focusWidget->resize ();
		}
	}

	virtual void applyTheme (BStyles::Theme& theme) override
	{
		applyTheme (theme, name_);
	}

protected:
        virtual void draw (const double x, const double y, const double width, const double height) override
        {

        	if ((!widgetSurface) || (cairo_surface_status (widgetSurface) != CAIRO_STATUS_SUCCESS)) return;

        	if ((width_ >= 6) && (height_ >= 6))
        	{
        		// Draw super class widget elements first
        		Button::draw (x, y, width, height);

        		cairo_t* cr = cairo_create (widgetSurface);
        		if (cairo_status (cr) == CAIRO_STATUS_SUCCESS)
        		{
                                // Limit cairo-drawing area
                		cairo_rectangle (cr, x, y, width, height);
                		cairo_clip (cr);

                		double x0 = getXOffset ();
                		double y0 = getYOffset ();
                		double w = getEffectiveWidth ();
                		double h = getEffectiveHeight ();

                                cairo_set_line_width (cr, 1.0);
                                cairo_set_source_rgba (cr, CAIRO_RGBA (BColors::grey));

                                cairo_arc (cr, x0 + 0.5 * w, y0 + 0.5 * h, 0.333 * w, 0.25 * M_PI, - 0.25 * M_PI);
                                cairo_rel_line_to (cr, - w / 8, - h / 16);
                                cairo_rel_line_to (cr, w / 16, - h / 16);
                                cairo_rel_line_to (cr, w / 16, h / 8);

                                cairo_stroke (cr);
                        }
                        cairo_destroy (cr);
                }
        }
};

#endif /* UNDOBUTTON_HPP_ */
