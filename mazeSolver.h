#ifndef MAZESOLVER_H
#define MAZESOLVER_H


#include "vector.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QBrush>
#include "point.h"

class mazeSolver
{
private:

    vector<vector<char>> m_maze;   // Matrix representing the maze
    vector<vector<bool>> m_visited;   // Matrix to track visited cells in the maze
    vector<vector<CPoint>> m_parent;   // Matrix to store parent cells for backtracking
    vector<vector<QGraphicsRectItem *>> m_items;   // Matrix of graphical items for visualization
    int m_rows;    // Number of rows in the maze
    int m_cols;    // Number of columns in the maze

    CPoint m_start;   // Starting point in the maze
    CPoint m_target;  // Target (end) point in the maze
    CPoint m_edit;
    QString m_type;

public:
    static vector<CPoint> m_neighbors;  // Static vector to store neighbor points for traversal

    mazeSolver() {}
    mazeSolver(const size_t rows,const size_t cols, const QGraphicsView *view);
    mazeSolver(const size_t rows,const size_t cols, const QGraphicsView *view, const int startX, const int startY, const int endX, const int endY,const int editX,const int editY,QString type);
    size_t rows() const {return m_rows;}
    size_t cols() const {return m_cols;}
    void generate_maze();
    void print_maze() const;
    void resetMaze_colors();
    void display_maze(QGraphicsView* view); // Function to display the maze
    void display_solution();
    bool bfs();
    void resetMaze();
};

#endif // MAZESOLVER_H
