#ifndef DRAWSCENE
#define DRAWSCENE

#include <QGraphicsScene>
#include "drawtool.h"
#include "drawobj.h"

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
class QMenu;
class QPointF;
class QGraphicsLineItem;
class QFont;
class QGraphicsTextItem;
class QColor;
class QKeyEvent;
QT_END_NAMESPACE

class GraphicsItemGroup;

class DrawScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit DrawScene(QObject *parent = 0);
    void setView(QGraphicsView * view ) { m_view = view ; }
    QGraphicsView * view() { return m_view; };
    void mouseEvent(QGraphicsSceneMouseEvent *mouseEvent );
    GraphicsItemGroup * createGroup(const QList<QGraphicsItem *> &items);
    void destroyGroup(QGraphicsItemGroup *group);
signals:
    void itemSelected(QGraphicsItem *item);
    void itemMoved( QGraphicsItem * item , const QPointF & oldPosition );
    void itemRotate(QGraphicsItem * item , const qreal oldAngle );
    void itemAdded(QGraphicsItem * item );

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvet) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent *e) Q_DECL_OVERRIDE;
    void keyReleaseEvent(QKeyEvent *e) Q_DECL_OVERRIDE;
    QGraphicsView * m_view;

};

#endif // DRAWSCENE

