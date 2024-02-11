#ifndef TEXTFINDER_H
#define TEXTFINDER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class TextFinder;
}
QT_END_NAMESPACE

class TextFinder : public QMainWindow
{
    Q_OBJECT

public:
    TextFinder(QWidget *parent = nullptr);
    ~TextFinder();


private slots:
    void on_findButton_clicked();

private:
    Ui::TextFinder *ui;
    void loadTextFile();

};
#endif // TEXTFINDER_H
