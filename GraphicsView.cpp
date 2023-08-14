//********************************************************
/// @brief 
/// @author yanhuajian
/// @date 2023/8/14
/// @note
/// @version 1.0.0
//********************************************************

#include "GraphicsView.h"
#include <QGraphicsRectItem>
#include <QMouseEvent>

GraphicsView::GraphicsView(QWidget* parent)
: QGraphicsView(parent) {
    auto scene = new QGraphicsScene(this);
    setScene(scene);
    setSceneRect(0, 0, 600, 600);
    auto item = new QGraphicsRectItem(0, 0, 100, 100);
    item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    item->setBrush(QBrush(Qt::gray));
    item->setPos(200, 100);
    scene->addItem(item);
}

GraphicsView::~GraphicsView() {
}

void GraphicsView::mousePressEvent(QMouseEvent* event) {
    QGraphicsView::mousePressEvent(event);
}

void GraphicsView::mouseMoveEvent(QMouseEvent* event) {
    QGraphicsView::mouseMoveEvent(event);
    if(event->buttons() & Qt::LeftButton) {
        auto selItems = scene()->selectedItems();
        for(auto item : selItems) {
            //判断是否在吸附范围内
            auto topScenePosY = item->scenePos().y();
            auto bottomScenePosY = item->scenePos().y() + item->boundingRect().height();
            bool isTopAdsorb = topScenePosY >= 290 && topScenePosY <= 310;
            bool isBottomAdsorb = bottomScenePosY >= 290 && bottomScenePosY <= 310;
            int topOffset = qAbs(topScenePosY - 300);
            int bottomOffset = qAbs(bottomScenePosY - 300);
            //顶部离吸附线更近
            if(isTopAdsorb && topOffset < bottomOffset) {
                item->setPos(item->scenePos().x(), 300);
            }
            //底部离吸附线更近
            if(isBottomAdsorb && bottomOffset < topOffset) {
                item->setPos(item->scenePos().x(), 300 - item->boundingRect().height());
            }
        }
    }
}
void GraphicsView::mouseReleaseEvent(QMouseEvent* event) {
    QGraphicsView::mouseReleaseEvent(event);
}

void GraphicsView::drawForeground(QPainter *painter, const QRectF &rect) {
    QGraphicsView::drawForeground(painter, rect);
    painter->setPen(QPen(Qt::darkGreen, 1, Qt::DashLine));
    //绘制吸附范围
    painter->drawLine(0, 290, 600, 290);
    painter->drawLine(0, 310, 600, 310);
    //绘制吸附线
    painter->setPen(QPen(Qt::red, 1));
    painter->drawLine(0, 300, 600, 300);
}
