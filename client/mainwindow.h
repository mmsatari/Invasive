#pragma once
#include "stdafx.h"
#include "forward.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void frameDecoded();
    void selectionChanged();
    void setInputDevice(int index);
    void saveAsFile(bool selected = false);
    void saveSelectedAsFile();
    void openLogFile();
    void openWavFile();

private:
    void initializeSettings();
    void initializeMenuBar();
    void closeEvent(QCloseEvent *event);

private:
    ConfigDialog* config_dialog_;
    FrameListWidget* frame_list_;
    QTextBrowser* frame_browser_;
    WaterfallView *waterfall_;

    Modem* modem_;
    SocketServer* server_;
    FrameLogger* logger_;
    QActionGroup* input_action_group_;
    QAction* save_file_act_;
    QAction* save_selected_act_;
    QSettings settings_;

};
