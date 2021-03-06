/*Purpose: Provide a window to edit a chapter, options to add sections,
 *Delete sections from the list, and filling out a chapter information form are present
 *
 *Traceability: SS-02-01 (Part of Content Manager Interface Subsystem)
 */
#ifndef CREATECHAPTERFORMWINDOW_H
#define CREATECHAPTERFORMWINDOW_H

#include <QWidget>
#include "EditSectionFormWindow.h"
#include <QPushButton>

#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include <QListView>

class EditTextbookFormWindow;

namespace Ui {
class EditChapterFormWindow;
}

class EditChapterFormWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EditChapterFormWindow(QWidget *parent = 0);
    ~EditChapterFormWindow();

    QPushButton* getBackButton();
    QPushButton* getCreateButton();
    QPushButton* getCreateSectionButton();
    QPushButton* getEditSectionButton();
    QPushButton* getDeleteSectionButton();

    QLineEdit*      getTitleTextbox();
    QSpinBox*       getChapterNumberSpinBox();
    QDoubleSpinBox* getPriceSpinBox();
    QCheckBox*      getAvailabilityCheckBox();

    QListView*      getSectionsListView();


private:
    Ui::EditChapterFormWindow *ui;
    EditSectionFormWindow editSectionForm;
};

#endif // CREATECHAPTERFORMWINDOW_H
