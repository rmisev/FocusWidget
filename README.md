# FocusWidget

FocusWidget is simple Qt widget which prevents QWebEngineView to take focus on `load(...)` and `setHtml(...)` cals.

How to use? Just place QWebEngineView as child into FocusWidget, sample:

```c++
QSplitter page;

QWebEngineView* webView = new QWebEngineView;
FocusWidget* focusWidget = new FocusWidget;
focusWidget->setChildWidget(webView);
page.addWidget(focusWidget);
```

Repository contains FocusWidget class files (cpp, h) and sample application.
