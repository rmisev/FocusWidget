// The MIT License (MIT)
//
// Copyright (c) 2016 Rimas Misevičius
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <QApplication>
#include <QFocusEvent>
#include "FocusWidget.h"


FocusWidget::FocusWidget(QWidget *parent)
    : QWidget(parent)
    , childWidget(nullptr)
{
    setEnabled(true);
    setFocusPolicy(Qt::StrongFocus);

    // to catch, when childWidget (and its children) loses focus
    connect(qApp, &QApplication::focusChanged, this, &FocusWidget::onFocusChanged);
}

void FocusWidget::setChildWidget(QWidget *child)
{
    childWidget = child;
    childWidget->setParent(this);
    childWidget->setEnabled(false);
}

void FocusWidget::focusInEvent(QFocusEvent *event)
{
    // Make sure the rest of events are handled
    QWidget::focusInEvent(event);

    if (childWidget) {
        // transfer focus to childWidget
        childWidget->setEnabled(true);
        childWidget->setFocus(event->reason());
        setFocusPolicy(Qt::NoFocus);
    }
}

void FocusWidget::resizeEvent(QResizeEvent *event)
{
    if (childWidget)
        childWidget->resize(event->size());
}

QSize FocusWidget::sizeHint() const
{
    if (childWidget)
        return childWidget->sizeHint();
    return QWidget::sizeHint();
}

void FocusWidget::onFocusChanged(QWidget * /*old*/, QWidget *now)
{
    if (childWidget && childWidget->isEnabled() && now) {
        for (QWidget *p = now; p != nullptr; p = p->parentWidget()) {
            if (p == childWidget) return;
        }
        // childWidget and its children lost focus
        childWidget->setEnabled(false);
        setFocusPolicy(Qt::StrongFocus);
    }
}
