#ifndef MANAGECOURSESINTERFACEWINDOW_H
#define MANAGECOURSESINTERFACEWINDOW_H
#include <QPushButton>
#include <QWidget>
#include <QComboBox>

namespace Ui {
class ManageCoursesInterfaceWindow;
}

class ManageCoursesInterfaceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ManageCoursesInterfaceWindow(QWidget *parent = 0);
    ~ManageCoursesInterfaceWindow();
    static ManageCoursesInterfaceWindow* getInstance();

    QPushButton* getBackButton();
    QPushButton* getCreateCourseButton();
    QPushButton* getEditCourseButton();
    QPushButton* getDeleteCourseButton();
    QComboBox*   getTermSelectOption();
    QPushButton* getEnrollStudentOption();
    QPushButton* getAssignTextbookOption();

    QAbstractItemView* getCourseListView();
    QAbstractItemView* getRegisteredStudentsListView();
    QAbstractItemView* getAssignedTextbooksListView();

private:
    Ui::ManageCoursesInterfaceWindow *ui;
    static ManageCoursesInterfaceWindow* instance;
};

#endif // MANAGECOURSESINTERFACEWINDOW_H
