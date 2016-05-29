#include <QApplication>
#include <QListWidget>
#include <QSplitter>
#include <QWebEngineView>
#include "FocusWidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // interior
    QSplitter page;

    QListWidget *listWidget = new QListWidget;
    new QListWidgetItem("https://example.com/", listWidget);
    new QListWidgetItem("https://duckduckgo.com/", listWidget);
    new QListWidgetItem("https://www.wikipedia.org/", listWidget);
    listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    page.addWidget(listWidget);

    // add FocusWidget as parent for QWebEngineView
    QWebEngineView* webView = new QWebEngineView;
    FocusWidget* focusWidget = new FocusWidget;
    focusWidget->setChildWidget(webView);
    page.addWidget(focusWidget);

    QObject::connect(listWidget, &QListWidget::currentItemChanged,
        [=](QListWidgetItem *current, QListWidgetItem*){
            if (current) {
                webView->load(current->text());
            } else {
                webView->setHtml("<!DOCTYPE html>");
            }
        });
    listWidget->setCurrentRow(0);

    page.setWindowTitle("FocusWidget test");
    page.show();

    return app.exec();
}
