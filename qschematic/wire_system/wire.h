#pragma once

#include <QList>
#include "items/wirepoint.h"

namespace QSchematic {
    class Wire;
}

using namespace QSchematic; // TODO: Needs to be removed

namespace wire_system
{
    class wire_manager;

    class wire
    {

    public:
        wire();
        void set_manager(wire_manager* manager);
        QVector<WirePoint> points() const;
        int points_count() const;
        QVector<int> junctions() const;
        QList<Wire*> connected_wires();
        QList<Line> line_segments() const;
        virtual void move_point_to(int index, const QPointF& moveTo);
        void set_point_is_junction(int index, bool isJunction);
        virtual void prepend_point(const QPointF& point);

    protected: // TODO: All these members should be private
        void move_junctions_to_new_segment(const Line& oldSegment, const Line& newSegment);
        virtual void about_to_change();
        virtual void has_changed();

        wire_manager* m_manager;
        QVector<WirePoint> _points;
        QList<Wire*> _connectedWires; // TODO: Should be QList<wire_system::wire>
    };
}