//********************************************************
/// @brief 
/// @author yanhuajian
/// @date 2023/8/14
/// @note
/// @version 1.0.0
//********************************************************

#pragma once

#include <QGraphicsScene>
#include <QGraphicsView>

class GraphicsView : public QGraphicsView {
public:
    explicit GraphicsView(QWidget* parent = nullptr);
    ~GraphicsView();

    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

    void drawForeground(QPainter* painter, const QRectF& rect) override;
};
