#include "header.h"
#include "MST.h"
#include "BaseEngine.h"

#include <queue>

using namespace std;

struct Node {
	int x, y;
};

struct Edge {
	int src, dest;
	double weight;
	bool operator<(const Edge other) const {
		return weight > other.weight;
	}
};

double calculateDistance(Node p1, Node p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

vector<Edge> minimumSpanningTree(vector<Node> points) {
    vector<bool> visited(points.size(), false);
    priority_queue<Edge> pq;

    visited[0] = true;
    for (int i = 1; i < points.size(); i++) {
        Edge edge;
        edge.src = 0;
        edge.dest = i;
        edge.weight = calculateDistance(points[0], points[i]);
        pq.push(edge);
    }

    vector<Edge> mst;
    while (!pq.empty()) {
        Edge edge = pq.top();
        pq.pop();
        if (visited[edge.dest]) {
            continue;
        }
        visited[edge.dest] = true;
        mst.push_back(edge);
        for (int i = 0; i < points.size(); i++) {
            if (!visited[i]) {
                Edge newEdge;
                newEdge.src = edge.dest;
                newEdge.dest = i;
                newEdge.weight = calculateDistance(points[edge.dest], points[i]);
                pq.push(newEdge);
            }
        }
    }
    return mst;
}

void MST::virtDraw()
{ 
    if (isVisible() && getEngine()->getNonNullObjectContentCount() > 4)
    {
        vector<Node> points;
        for (int i = 4; getEngine()->getDisplayableObject(i) != NULL; i++)
        {
            DisplayableObject* ufo = getEngine()->getDisplayableObject(i);
            Node p;
            p.x = ufo->getXCentre();
            p.y = ufo->getYCentre();
            points.push_back(p);
        }

        vector<Edge> mst = minimumSpanningTree(points);

        for (Edge edge : mst) {
            Node src = points[edge.src];
            Node dest = points[edge.dest];
            getEngine()->drawForegroundLine(src.x, src.y, dest.x, dest.y, 0xFFFFFF);
        }
    }
}