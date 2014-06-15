#pragma once
#include <QGLWidget>
#include "stdafx.h"

class WaterfallView : public QGLWidget
{
    Q_OBJECT
public:
    explicit WaterfallView(QWidget *parent = 0);

private:
    void paintEvent(QPaintEvent *event);
    void initializeGL();

public slots:
    void updateAudioSpectrum(const QVector<float>& data);
    void setDecordedPackets(int count);

private slots:
    void animate();

private:
    QTimer timer_;
    GLuint line_texture_;
    GLuint textures_[2];
    GLuint framebuffers_[2];
    int count_;
    QVector<float> line_buffer_;

    int decorded_packets_;
};