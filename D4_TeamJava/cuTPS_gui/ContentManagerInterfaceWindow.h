#ifndef CONTENTMANAGERINTERFACEWINDOW_H
#define CONTENTMANAGERINTERFACEWINDOW_H

#include <QWidget>

namespace Ui {
class ContentManagerInterfaceWindow;
}

class ContentManagerInterfaceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ContentManagerInterfaceWindow(QWidget *parent = 0);
    ~ContentManagerInterfaceWindow();

private:
    Ui::ContentManagerInterfaceWindow *ui;
};

#endif // CONTENTMANAGERINTERFACEWINDOW_H