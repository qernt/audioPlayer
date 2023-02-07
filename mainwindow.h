#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QTime>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_PlayPause_clicked();
    void on_horizontalSlider_Volume_valueChanged();   
    void progress_bar_change();
    void on_horizontalSlider_Timeline_valueChanged();
    void on_horizontalSlider_Timeline_sliderPressed();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QAudioOutput *audioOutput;
    QMediaPlayer *player;
};
#endif // MAINWINDOW_H
