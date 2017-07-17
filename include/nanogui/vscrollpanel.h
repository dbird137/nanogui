/*
    nanogui/vscrollpanel.h -- Adds a vertical scrollbar around a widget
    that is too big to fit into a certain area

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/
/** \file */

#pragma once

#include <nanogui/widget.h>

NAMESPACE_BEGIN(nanogui)

/**
 * \class VScrollPanel vscrollpanel.h nanogui/vscrollpanel.h
 *
 * \brief Adds a vertical scrollbar around a widget that is too big to fit into
 *        a certain area.
 */
class NANOGUI_EXPORT VScrollPanel : public Widget {
public:
    VScrollPanel(Widget *parent);

    virtual void perform_layout(NVGcontext *ctx) override;
    virtual Vector2i preferred_size(NVGcontext *ctx) const override;
    virtual bool mouse_drag_event(const Vector2i &p, const Vector2i &rel, int button, int modifiers) override;
    virtual bool scroll_event(const Vector2i &p, const Vector2f &rel) override;
    virtual void draw(NVGcontext *ctx) override;
protected:
    int m_child_preferred_height;
    float m_scroll;
    bool m_update_layout;
};

NAMESPACE_END(nanogui)
