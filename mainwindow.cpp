#include "mainwindow.h"
#include "ui_mainwindow.h"


QString audioUrl;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    audioOutput = new QAudioOutput;
    player = new QMediaPlayer;

    audioOutput->setVolume(ui->horizontalSlider_Volume->sliderPosition() / 100.0);

    player->setAudioOutput(audioOutput);

    connect(player,SIGNAL(positionChanged(qint64)), this, SLOT(progress_bar_change()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_PlayPause_clicked()
{
    if((player->playbackState() == 0 | player->playbackState() == 2) & audioUrl != "")
    {
        ui->horizontalSlider_Timeline->setMaximum(player->duration());
        QTime time = QTime::fromMSecsSinceStartOfDay(player->duration());
        ui->label_duration->setText(time.toString("mm:ss"));
        ui->pushButton_PlayPause->setText("pause");
        player->play();
        player->PlayingState;
    }else if(player->playbackState() == 1)
    {
        player->pause();
        ui->pushButton_PlayPause->setText("play");
        player->PausedState;
    }

}


void MainWindow::on_horizontalSlider_Volume_valueChanged()
{
    audioOutput->setVolume(ui->horizontalSlider_Volume->sliderPosition() / 100.0);
}

void MainWindow::progress_bar_change()
{
    ui->horizontalSlider_Timeline->setSliderPosition(player->position());
    QTime time = QTime::fromMSecsSinceStartOfDay(player->position());
    ui->label_presenTime->setText(time.toString("mm:ss"));
}


void MainWindow::on_horizontalSlider_Timeline_valueChanged()
{
    if(ui->horizontalSlider_Timeline->isSliderDown() & player->playbackState() == 1)
    {
        player->pause();
        player->setPosition(ui->horizontalSlider_Timeline->value());
        player->play();
    }else if(ui->horizontalSlider_Timeline->isSliderDown())
    {
        player->setPosition(ui->horizontalSlider_Timeline->value());
    }
}


void MainWindow::on_horizontalSlider_Timeline_sliderPressed()
{
    player->setPosition(ui->horizontalSlider_Timeline->value());
}



void MainWindow::on_pushButton_clicked()
{
    QString audioUrlControl = audioUrl;
    audioUrl = QFileDialog::getOpenFileName(this, tr("Open File"),"/home",tr("Audio (*.mp3)"));
    if(!(audioUrlControl == audioUrl))
    {
        QFile audio(audioUrl);
        player->setSource(QUrl::fromLocalFile(audioUrl));
        player->StoppedState;
        ui->pushButton_PlayPause->setText("play");
    }
}

