#include <stdio.h>
#include <math.h>
  
#define MaxLength 100    //�������ȶ��У�Open��������
#define Height     15    //��ͼ�߶�
#define Width      20    //��ͼ���
  
#define Reachable   0    //���Ե���Ľ��
#define Bar         1    //�ϰ���
#define Pass        2    //��Ҫ�ߵĲ���
#define Source      3    //���
#define Destination 4    //�յ�
  
#define Sequential  0    //˳�����
#define NoSolution  2    //�޽������
#define Infinity    0xfffffff
  
#define East       (1 << 0)
#define South_East (1 << 1)
#define South      (1 << 2)
#define South_West (1 << 3)
#define West       (1 << 4)
#define North_West (1 << 5)
#define North      (1 << 6)
#define North_East (1 << 7)
  
typedef struct
{
    signed char x, y;
} Point;
  
const Point dir[8] =
{
    {0, 1},   // East
    {1, 1},   // South_East
    {1, 0},   // South
    {1, -1},  // South_West
    {0, -1},  // West
    {-1, -1}, // North_West
    {-1, 0},  // North
    {-1, 1}   // North_East
};
  
unsigned char within(int x, int y)
{
    return (x >= 0 && y >= 0
        && x < Height && y < Width);
}
  
typedef struct
{
    int x, y;
    unsigned char reachable, sur, value;
} MapNode;
  
typedef struct Close
{
    MapNode *cur;
    char vis;
    struct Close *from;
    float F, G;
    int H;
} Close;
  
typedef struct //���ȶ��У�Open��
{
    int length;        //��ǰ���еĳ���
    Close* Array[MaxLength];    //���۽���ָ��
} Open;
  
static MapNode graph[Height][Width];
static int srcX, srcY, dstX, dstY;    //��ʼ�㡢�յ�
static Close close[Height][Width];
  
  
  
//�����ͼ
static int map[Height][Width] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

const char Symbol[5][3] = { "��", "��", "��", "��", "��" };


// ���ȶ��л�������
void initOpen(Open *q)    //���ȶ��г�ʼ��
{
    q->length = 0;        // ����Ԫ������ʼΪ0
}
  
void push(Open *q, Close cls[Height][Width], int x, int y, float g)
{    //�����ȶ��У�Open�������Ԫ��
    Close *t;
    int i, mintag;
    cls[x][y].G = g;    //����ӽڵ������
    cls[x][y].F = cls[x][y].G + cls[x][y].H;
    q->Array[q->length++] = &(cls[x][y]);
    mintag = q->length - 1;
    for (i = 0; i < q->length - 1; i++)
    {
        if (q->Array[i]->F < q->Array[mintag]->F)
        {
            mintag = i;
        }
    }
    t = q->Array[q->length - 1];
    q->Array[q->length - 1] = q->Array[mintag];
    q->Array[mintag] = t;    //�����ۺ���ֵ��С�ڵ����ڶ�ͷ
}
  
Close* shift(Open *q)
{
    return q->Array[--q->length];
}
  
// ��ͼ��ʼ������
void initClose(Close cls[Height][Width], int sx, int sy, int dx, int dy)
{    // ��ͼClose���ʼ������
    int i, j;
    for (i = 0; i < Height; i++)
    {
        for (j = 0; j < Width; j++)
        {
            cls[i][j].cur = &graph[i][j];              // Close����ָ�ڵ�
            cls[i][j].vis = !graph[i][j].reachable;    // �Ƿ񱻷���
            cls[i][j].from = NULL;                     // �����ڵ�
            cls[i][j].G = cls[i][j].F = 0;
            cls[i][j].H = abs(dx - i) + abs(dy - j);    // ���ۺ���ֵ
        }
    }
    cls[sx][sy].F = cls[sx][sy].H;   //��ʼ�����۳�ʼֵ
    cls[dx][dy].G = Infinity;
}
  
void initGraph(int sx, int sy, int dx, int dy)
{
    int i, j;
    srcX = sx;    //���X����
    srcY = sy;    //���Y����
    dstX = dx;    //�յ�X����
    dstY = dy;    //�յ�Y����
    for (i = 0; i < Height; i++)
    {
        for (j = 0; j < Width; j++)
        {
            graph[i][j].x = i; 
            graph[i][j].y = j;
            graph[i][j].value = map[i][j];
            graph[i][j].reachable = (graph[i][j].value == Reachable); 
            graph[i][j].sur = 0; 
            if (!graph[i][j].reachable)
            {
                continue;
            }
            if (j > 0)
            {
                if (graph[i][j - 1].reachable)
                {
                    graph[i][j].sur |= West;
                    graph[i][j - 1].sur |= East;
                }
                if (i > 0)
                {
                    if (graph[i - 1][j - 1].reachable
                        && graph[i - 1][j].reachable
                        && graph[i][j - 1].reachable)
                    {
                        graph[i][j].sur |= North_West;
                        graph[i - 1][j - 1].sur |= South_East;
                    }
                }
            }
            if (i > 0)
            {
                if (graph[i - 1][j].reachable)
                {
                    graph[i][j].sur |= North;
                    graph[i - 1][j].sur |= South;
                }
                if (j < Width - 1)
                {
                    if (graph[i - 1][j + 1].reachable
                        && graph[i - 1][j].reachable
                        && map[i][j + 1] == Reachable)
                    {
                        graph[i][j].sur |= North_East;
                        graph[i - 1][j + 1].sur |= South_West;
                    }
                }
            }
        }
    }
}
  
int bfs()
{
    int times = 0;
    int i, curX, curY, surX, surY;
    unsigned char f = 0, r = 1;
    Close *p;
    Close* q[MaxLength] = { &close[srcX][srcY] };
  
    initClose(close, srcX, srcY, dstX, dstY);
    close[srcX][srcY].vis = 1;
  
    while (r != f)
    {
        p = q[f];
        f = (f + 1) % MaxLength;
        curX = p->cur->x;
        curY = p->cur->y;
        for (i = 0; i < 8; i++)
        {
            if (! (p->cur->sur & (1 << i)))
            {
                continue;
            }
            surX = curX + dir[i].x;
            surY = curY + dir[i].y;
            if (! close[surX][surY].vis)
            {
                close[surX][surY].from = p;
                close[surX][surY].vis = 1;
                close[surX][surY].G = p->G + 1;
                q[r] = &close[surX][surY];
                r = (r + 1) % MaxLength;
            }
        }
        times++;
    }
    return times;
}
  
int astar()
{
    //int times = 0;
    int i, curX, curY, surX, surY;
    float surG;
    Open q;
    Close *p;
  
    initOpen(&q);
    initClose(close, srcX, srcY, dstX, dstY);
    close[srcX][srcY].vis = 1;
    push(&q, close, srcX, srcY, 0);
  
    while (q.length)
    {    //times++;
        p = shift(&q);
        curX = p->cur->x;
        curY = p->cur->y;
        if (!p->H)
        {
            return Sequential;
        }
        for (i = 0; i < 8; i++)
        {
            if (! (p->cur->sur & (1 << i)))
            {
                continue;
            }
            surX = curX + dir[i].x;
            surY = curY + dir[i].y;
            if (!close[surX][surY].vis)
            {
                close[surX][surY].vis = 1;
                close[surX][surY].from = p;
                surG = p->G + sqrt((curX - surX) * (curX - surX) + (curY - surY) * (curY - surY));
                push(&q, close, surX, surY, surG);
            }
        }
    }
    return NoSolution;
}


void printMap()
{
    int i, j;
    for (i = 0; i < Height; i++)
    {
        for (j = 0; j < Width; j++)
        {
            printf("%s", Symbol[graph[i][j].value]);
        }
        puts("");
    }
    puts("");
}
  
Close* getShortest()
{
    int result = astar();
    Close *p, *t, *q = NULL;
    switch(result)
    {
    case Sequential:
        p = &(close[dstX][dstY]);
        while (p) 
        {
            t = p->from;
            p->from = q;
            q = p;
            p = t;
        }
        close[srcX][srcY].from = q->from;
        return &(close[srcX][srcY]);
    case NoSolution:
        return NULL;
    }
    return NULL;
}


static Close *start;
static int shortestep;
int printShortest()
{
    Close *p;
    int step = 0;
  
    p = getShortest();
    start = p;
    if (!p)
    {
        return 0;
    }
    else
    {
        while (p->from)
        {
            graph[p->cur->x][p->cur->y].value = Pass;
            printf("��%d��%d����\n", p->cur->x, p->cur->y);
            p = p->from;
            step++;
        }
        printf("��%d��%d��\n", p->cur->x, p->cur->y);
        graph[srcX][srcY].value = Source;
        graph[dstX][dstY].value = Destination;
        return step;
    }
}
  
void clearMap()
{    // Clear Map Marks of Steps
    Close *p = start;
    while (p)
    {
        graph[p->cur->x][p->cur->y].value = Reachable;
        p = p->from;
    }
    graph[srcX][srcY].value = map[srcX][srcY];
    graph[dstX][dstY].value = map[dstX][dstY];
}
  
void printDepth()
{
    int i, j;
    for (i = 0; i < Height; i++)
    {
        for (j = 0; j < Width; j++)
        {
            if (map[i][j])
            {
                printf("%s ", Symbol[graph[i][j].value]);
            }
            else
            {
                printf("%2.0lf ", close[i][j].G);
            }
        }
        puts("");
    }
    puts("");
}
  
void printSur()
{
    int i, j;
    for (i = 0; i < Height; i++)
    {
        for (j = 0; j < Width; j++)
        {
            printf("%02x ", graph[i][j].sur);
        }
        puts("");
    }
    puts("");
}
  
void printH()
{
    int i, j;
    for (i = 0; i < Height; i++)
    {
        for (j = 0; j < Width; j++)
        {
            printf("%02d ", close[i][j].H);
        }
        puts("");
    }
    puts("");
}
  
int main(int argc, const char **argv)
{

    printMap();
    printf("please set the barrier of this map,such as 1 1 if you don not want to set barrier an more, please enter 100 100\n");
    
    int barrierX,barrierY;
    while(scanf("%d %d",&barrierX,&barrierY) != EOF ){
        if (within(barrierX, barrierY)){
            map[barrierX][barrierY] = 1;
        }else{
            puts("input error");
        }
        if(barrierX == 100 && barrierY == 100){
            break;
        }
    }
    
    initGraph(0, 0, 0, 0);
    printMap();
    
    printf("please enter the posion of start and end, for example 0 0 10 10\n");
    while (scanf("%d %d %d %d", &srcX, &srcY, &dstX, &dstY) != EOF)
    {
        if (within(srcX, srcY) && within(dstX, dstY))
        {
            if (shortestep = printShortest())
            {
                printf("the latest path from��%d��%d��to��%d��%d��is: %d\n",
                    srcX, srcY, dstX, dstY, shortestep);
                printMap();
                clearMap();
                bfs();
                //printDepth();
                puts((shortestep == close[dstX][dstY].G) ? "right" : "error");
                clearMap();
            }
            else
            {
                printf("��%d��%d��can not reach��%d��%d��\n",
                    srcX, srcY, dstX, dstY);
            }
        }
        else
        {
            puts("input error");
        }
    }
    return (0);
}