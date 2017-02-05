#include <QApplication>
#include <QListWidget>
#include <QSplitter>
#include <QWebEngineView>

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

    QWebEngineView* webView = new QWebEngineView;
    page.addWidget(webView);

    QObject::connect(listWidget, &QListWidget::currentItemChanged,
        [webView](QListWidgetItem *current, QListWidgetItem*){
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
