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

#ifndef FOCUSWIDGET_H
#define FOCUSWIDGET_H

#include <QWidget>

class QFocusEvent;

class FocusWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FocusWidget(QWidget *parent = 0);
    void setChildWidget(QWidget *child);

protected:
    void focusInEvent(QFocusEvent *event);
    void resizeEvent(QResizeEvent *event);
    QSize sizeHint() const;

private slots:
    void onFocusChanged(QWidget *old, QWidget *now);

protected:
    QWidget *childWidget;
};

#endif // FOCUSWIDGET_H
