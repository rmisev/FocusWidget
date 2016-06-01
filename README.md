# FocusWidget

FocusWidget is simple Qt widget which prevents QWebEngineView to take focus on `load(...)` and `setHtml(...)` calls.

How to use? Just place QWebEngineView as child into FocusWidget, for example:

```c++
QSplitter page;

QWebEngineView* webView = new QWebEngineView;
FocusWidget* focusWidget = new FocusWidget;
focusWidget->setChildWidget(webView);
page.addWidget(focusWidget);
```

Repository contains the source code of FocusWidget class and sample application.
