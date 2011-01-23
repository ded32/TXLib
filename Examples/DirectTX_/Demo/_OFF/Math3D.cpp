
/**\file     Demo/Math.cpp
 *
 * \brief    Пример для DirectTX - 3D math libraries
 *
 * \version  [v 0.2]
 *
 * \author   Copyright (C) Nikita Uvarov, 7 класс
 * \date     2009
 */

#include "..\DirectTX.cpp"

#include <vector>
using std::vector;

/* 3D basics */

struct Matrix
    {
    float matrix [4] [4];

    Matrix (bool nullMatrix = false)
        {
        nullMatrix = !nullMatrix;

        for (int j = 0; j < 4; j++)
        for (int i = 0; i < 4; i++)
            matrix [i] [j] = ((i == j) & nullMatrix ? 1 : 0);
        }

    Matrix (float m00, float m10, float m20, float m30, float m01, float m11, float m21, float m31, float m02, float m12, float m22, float m32, float m03, float m13, float m23, float m33)
        {
        matrix [0] [0] = m00; matrix [1] [0] = m10; matrix [2] [0] = m20; matrix [3] [0] = m30;
        matrix [0] [1] = m01; matrix [1] [1] = m11; matrix [2] [1] = m21; matrix [3] [1] = m31;
        matrix [0] [2] = m02; matrix [1] [2] = m12; matrix [2] [2] = m22; matrix [3] [2] = m32;
        matrix [0] [3] = m03; matrix [1] [3] = m13; matrix [2] [3] = m23; matrix [3] [3] = m33;
        }

    Matrix (float m00, float m10, float m20, float m01, float m11, float m21, float m02, float m12, float m22)
        {
        matrix [0] [0] = m00; matrix [1] [0] = m10; matrix [2] [0] = m20; matrix [3] [0] = 0;
        matrix [0] [1] = m01; matrix [1] [1] = m11; matrix [2] [1] = m21; matrix [3] [1] = 0;
        matrix [0] [2] = m02; matrix [1] [2] = m12; matrix [2] [2] = m22; matrix [3] [2] = 0;
        matrix [0] [3] =   0; matrix [1] [3] =   0; matrix [2] [3] =   0; matrix [3] [3] = 1;
        }

    void DrawMatrix (int x, int y, COLORREF c)
        {
        txSetColor (c);

        for (int i = 0; i < 4; i++)
            {
            char rowBuf [40] = "";
            sprintf (rowBuf, "[%.1f %.1f %.1f %.1f]",  matrix [0] [i], matrix [1] [i],
                                                       matrix [2] [i], matrix [3] [i]);
            txTextOut (x, y + i * 12, rowBuf);
            }
        }

    float* operator [] (int i)
        {
        return & (matrix [i] [0]);
        }

    Matrix operator * (float a)
        {
        Matrix result;

        for (int j = 0; j < 4; j++)
        for (int i = 0; i < 4; i++)
            result.matrix [i] [j] = matrix [i] [j] * a;

        return result;
        }

    Matrix operator * (Matrix m)
        {
        Matrix newMatrix (true);

        for (int j = 0; j < 4; j++)
        for (int i = 0; i < 4; i++)
            for (int t = 0; t < 4; t++)
            newMatrix.matrix [i] [j] += matrix [t] [j] * m.matrix [i] [t];

        return newMatrix;
        }
    };

// Implementation of camera in [0, 0, -dist] that looks at [0, 0, 0]

struct ProjectionCamera
    {
    int dist,
        screenSizeX,
        screenSizeY;

    ProjectionCamera (int dist, int screenSizeX, int screenSizeY) :
        dist (dist),
        screenSizeX (screenSizeX),
        screenSizeY (screenSizeY)
        {}
    };

struct Vector
    {
    float vx, vy, vz, vt;

    Vector() :
        vx (0),
        vy (0),
        vz (0),
        vt (1)
        {}

    Vector (float vx, float vy, float vz) :
        vx (vx),
        vy (vy),
        vz (vz),
        vt (1)
        {}

    Vector (float vx, float vy, float vz, float vt) :
        vx (vx),
        vy (vy),
        vz (vz),
        vt (vt)
        {}

    Vector operator * (Matrix& multBy)
        {
        Vector newVector;

        newVector.vx = vx * multBy [0] [0] + vy * multBy [1] [0] + vz * multBy [2] [0] + vt * multBy [3] [0];
        newVector.vy = vx * multBy [0] [1] + vy * multBy [1] [1] + vz * multBy [2] [1] + vt * multBy [3] [1];
        newVector.vz = vx * multBy [0] [2] + vy * multBy [1] [2] + vz * multBy [2] [2] + vt * multBy [3] [2];
        newVector.vt = 1;

        return newVector;
        }

    static inline Vector VectorMultiply (Vector a, Vector b)
        {
        return Vector (a.vy * b.vz - b.vy * a.vz,
                       a.vz * b.vx - b.vz * a.vx,
                       a.vx * b.vy - b.vx * a.vy);
        }

    static inline float ScalarMultiply (Vector a, Vector b)
        {
        return a.vx * b.vx + a.vy * b.vy + a.vz * b.vz;
        }

    Vector operator * (Vector v)
        {
        return VectorMultiply (*this, v);
        }

    Vector operator * (float alpha)
        {
        return Vector (vx * alpha, vy * alpha, vz * alpha, 1);
        }

    Vector operator * (ProjectionCamera& multBy)
        {
        return Vector (multBy.screenSizeX / 2 + vx * multBy.dist / (vz + multBy.dist),
                       multBy.screenSizeY / 2 + vy * multBy.dist / (vz + multBy.dist), 0, 0);
        }

    Vector operator + (Vector v)
        {
        return Vector (v.vx + vx, v.vy + vy, v.vz + vz);
        }

    Vector operator - (Vector v)
        {
        return Vector (v.vx - vx, v.vy - vy, v.vz - vz);
        }

    bool operator != (Vector v)
        {
        return (vx != v.vx) || (vy != v.vy) || (vz != v.vz);
        }

    float& operator [] (int i)
        {
        return (&vx) [i];
        }

    void Check()
        {
        if (vx > 1000 || vy > 1000 || vz > 1000)
            {
            printf ("Vector : %f %f %f %f\n", vx, vy, vz, vt);
            txSleep (100);
            }
        }

    float Length()
        {
        return sqrt (vx * vx + vy * vy + vz * vz);
        }

    Vector ToIdentity()
        {
        float vLength = Length();

        if (vLength == 0)
            {
            return Vector (0, 0, 0, 0);
            }
        else
            {
            float  m = sqrtf (1.0 / vLength);
            return Vector (vx * m, vy * m, vz * m, 1);
            }
        }
    };

/* Standard Matrix */

inline Matrix CreateTranslationMatrix (float x, float y, float z)
    {
    return Matrix (1, 0, 0, x,
                   0, 1, 0, y,
                   0, 0, 1, z,
                   0, 0, 0, 1);
    }

inline Matrix CreateScaleMatrix (float x, float y, float z)
    {
    return Matrix (x, 0, 0, 0,
                   0, y, 0, 0,
                   0, 0, z, 0,
                   0, 0, 0, 1);
    }

enum Axis
    {
    XAXIS,
    YAXIS,
    ZAXIS
    };

// TODO : Create Quaternions and rotation around given vector

inline Matrix CreateAxisRotationMatrix (Axis axis, float r)
    {
    float radAngle = r* txPI / 180.0;

    if (axis == XAXIS)
        return Matrix (1, 0,               0,              0,
                       0, cos (radAngle), -sin (radAngle), 0,
                       0, sin (radAngle),  cos (radAngle), 0,
                       0, 0,               0,              1);

    else if (axis == YAXIS)
        return Matrix ( cos (radAngle), 0, sin (radAngle), 0,
                        0,              1, 0,              0,
                       -sin (radAngle), 0, cos (radAngle), 0,
                        0,              0, 0,              1);
    else
        return Matrix (cos (radAngle), -sin (radAngle), 0, 0,
                       sin (radAngle),  cos (radAngle), 0, 0,
                       0,               0,              1, 0,
                       0,               0,              0, 1);
    }

void DrawFace (Vector a, Vector b, Vector c)
    {
    POINT polygon [3] = {{ (int) a.vx, (int) a.vy },
                         { (int) b.vx, (int) b.vy },
                         { (int) c.vx, (int) c.vy }};
    txPolygon (polygon, 3);
    }

enum PostFrameInfo
    {
    PFI_RENDEREDIN,
    PFI_FPS,
    PFI_NOTHING
    };

long FrameBegin = 0;

void BeginFrame()
    {
    FrameBegin = GetTickCount();
    txBegin();
    }

void EndFrame (PostFrameInfo whatToDraw = PFI_NOTHING)
    {
    long frameEnd = GetTickCount();
    if (whatToDraw != PFI_NOTHING)
        {
        long renderedIn  = frameEnd - FrameBegin;
        long fps         = 1000 / (renderedIn + 1);

        char buf [100] = "";
        if (whatToDraw == PFI_FPS) sprintf (buf, "FPS : %i", fps);
        else                       sprintf (buf, "Rendered in : %i ms.", renderedIn);

        txTextOut (0, 0, buf);
        }

    txEnd();
    }

/* Ok. Let's continue */

struct Face
    {
    Vector* a, * b, * c;

    Face (Vector* a, Vector* b, Vector* c) :
        a (a),
        b (b),
        c (c)
        {}

    void Draw()
        {
        DrawFace (*a, *b, *c);
        }

    void Check()
        {
        a->Check();
        b->Check();
        c->Check();
        }
    };

struct Object
    {
    vector<Vector> vertexes;
    vector<Face>   faces;

    int AddVertex (Vector v)
        {
        vertexes.push_back (v);
        return vertexes.size() - 1;
        }

    void AddFace (int vai, int vbi, int vci)
        {
        faces.push_back (Face (& (vertexes [vai]),
                               & (vertexes [vbi]),
                               & (vertexes [vci])));
        }

    void Draw()
        {
        for (int i = 0; i < faces.size(); i++)
            faces [i] .Draw();
        }

    void DrawEx (Matrix& transformMatrix, ProjectionCamera& view)
        {
        for (int i = 0; i < faces.size(); i++)
            {
            Vector  newVectorA  = *faces [i].a * transformMatrix * view;
            Vector  newVectorB  = *faces [i].b * transformMatrix * view;
            Vector  newVectorC  = *faces [i].c * transformMatrix * view;

            DrawFace (newVectorA, newVectorB, newVectorC);
            }
        }

    void AddFace_BAD (Vector a, Vector b, Vector c)
        {
        int vai = AddVertex (a),
            vbi = AddVertex (b),
            vci = AddVertex (c);

        AddFace (vai, vbi, vci);
        }

    void Check()
        {
        for (int i = 0; i < faces.size(); i++)
            {
            printf ("Face number: %i\n", i);
            faces [i] .Check();
            }
        }
    };

/* Demo */

Object CreateHeightmap (bool randomHm = true, int* heightMap = 0,
                        int hsx = 10, int hsy = 10, int rectSize = 30)
    {
    int heightMapSizeX = hsx,
        heightMapSizeY = hsy;
    int randomHeightmap      [heightMapSizeX] [heightMapSizeY] = {};
    int heightMapVertexIndex [heightMapSizeX] [heightMapSizeY] = {};

    Object heightmap;

    for (int j = 0; j < heightMapSizeY; j++)
    for (int i = 0; i < heightMapSizeX; i++)
        {
        randomHeightmap [i] [j] = (randomHm)? rand() % 40 : heightMap [j * heightMapSizeX + i];

        heightMapVertexIndex [i] [j] = heightmap.AddVertex (Vector ((i - heightMapSizeX / 2) * rectSize,
                                                                    -randomHeightmap [i] [j],
                                                                    (j - heightMapSizeY / 2) * rectSize));
        }

    for (int j = 0; j < heightMapSizeY - 1; j++)
    for (int i = 0; i < heightMapSizeX - 1; i++)
        {
        int rectFirstID  = heightMapVertexIndex [i]   [j],
            rectSecondID = heightMapVertexIndex [i+1] [j],
            rectThirdID  = heightMapVertexIndex [i]   [j+1],
            rectFourthID = heightMapVertexIndex [i+1] [j+1];

        heightmap.AddFace (rectFirstID, rectSecondID, rectFourthID);
        heightmap.AddFace (rectFirstID, rectThirdID,  rectFourthID);
        }

    return heightmap;
    }

Object LoadOFF (const char* fileName)
    {
    FILE* file = fopen (fileName, "r");

    const char* normalOffSignature  = "OFF";
    char        offSignature [3] = {};

    fscanf (file, "%s\n", & (offSignature [0]));

    for (int i = 0; i < 4; i++)
        if (offSignature [i] != normalOffSignature [i])
            return Object();

    int numberOfPoints  = 0,
        numberOfFaces   = 0,
        numberOfEdges   = 0;

    Object object;

    fscanf (file, "%i %i %i", &numberOfPoints, &numberOfFaces, &numberOfEdges);

    object.vertexes.resize (numberOfPoints);

    for (int i = 0; i < numberOfPoints; i++)
        {
        double vx = 0, vy = 0, vz = 0;
        fscanf (file, "%lf %lf %lf", &vx, &vy, &vz);

        object.vertexes [i] = currentPoint (vx, vy, vz, 1);
        }

    for (int i = 0; i < numberOfFaces; i++)
        {
        int currentFacePoints = 0;
        fscanf (file, "%i", &currentFacePoints);

        int currentFace [currentFacePoints] = {};
        for (int j = 0; j < currentFacePoints; j++)
            fscanf (file, "%i", &currentFace [j]);

        /* Here is the code to break face into triangles.
           Nikster engine supports only convex polygons (3, 4 or 5 vertex each) */

        if (currentFacePoints == 3)
            object.AddFace (currentFace [0], currentFace [1], currentFace [2]);

        else if (currentFacePoints == 4)
            {
            object.AddFace (currentFace [0], currentFace [1], currentFace [3]);
            object.AddFace (currentFace [0], currentFace [2], currentFace [3]);
            }

        else if (currentFacePoints == 5)
            {
            object.AddFace (currentFace [0], currentFace [2], currentFace [1]);
            object.AddFace (currentFace [0], currentFace [2], currentFace [3]);
            object.AddFace (currentFace [0], currentFace [3], currentFace [4]);
            }
        }

    fclose (file);

    return object;
    }

void DrawAxis (Matrix& m, ProjectionCamera cam)
    {
    Vector begin = Vector (  0,   0,   0) * m * cam,
           xAxis = Vector (100,   0,   0) * m * cam,
           yAxis = Vector (  0, 100,   0) * m * cam,
           zAxis = Vector (  0,   0, 100) * m * cam;

    txSetColor (TX_RED, 5);
    txLine (begin.vx, begin.vy, xAxis.vx, xAxis.vy);
    txLine (begin.vx, begin.vy, yAxis.vx, yAxis.vy);
    txLine (begin.vx, begin.vy, zAxis.vx, zAxis.vy);
    }

/* Extra Math */

Vector CartesianToSpherical (Vector cartesian)
    {
    return Vector (cartesian.Length(),
                   atan2 (cartesian.vz, hypot (cartesian.vx, cartesian.vy)),
                   atan2 (cartesian.vx, cartesian.vy));
    }

Vector SphericalToCartesian (Vector spherical)
    {
    return Vector (spherical.vz * sin (spherical.vx) * cos (spherical.vy),
                   spherical.vz * sin (spherical.vx) * sin (spherical.vy),
                   spherical.vz * cos (spherical.vx));
    }

Vector SphereCoord (float latitude, float longtitude, float radius)
    {
    latitude   = ((int) (latitude   + 0.5) + 36000) % 360;
    longtitude = ((int) (longtitude + 0.5) + 36000) % 360;

    return Vector (latitude * txPI / 180.0, longtitude * txPI / 180.0, radius);
    }

Object CreateSphere (float r, float xStep, float yStep)
    {
    Object sphere;

    int until = 360;
    sphere.vertexes.resize (until * 90 * 3 * 2);

    for (float i =   0; i < until; i += xStep)
    for (float j = -90; j <    90; j += yStep)
        {
        sphere.AddFace_BAD (SphericalToCartesian (SphereCoord (i,         j,         r)),
                            SphericalToCartesian (SphereCoord (i + xStep, j,         r)),
                            SphericalToCartesian (SphereCoord (i,         j + yStep, r)));

        sphere.AddFace_BAD (SphericalToCartesian (SphereCoord (i + xStep, j + yStep, r)),
                            SphericalToCartesian (SphereCoord (i + xStep, j,         r)),
                            SphericalToCartesian (SphereCoord (i,         j + yStep, r)));
        }

    return sphere;
    }

/* OMG Quaternions */

struct Quaternion
    {
    float x, y, z, w;

    Quaternion() :
        x (0),
        y (0),
        z (0),
        w (1)
        {}

    Quaternion (float x, float y, float z, float w) :
        x (x),
        y (y),
        z (z),
        w (w)
        {}

    static Quaternion FromAxisAngle (float x, float y, float z, float w)
        {
        float sinw = sin (w / 2),
              cosw = cos (w / 2);

        float len2 = x*x + y*y + z*z;

        if (len2 != 0)
            {
            float len = sqrtf (1.0 / len2);

            x *= len;
            y *= len;
            z *= len;
            }

        Quaternion result (x * sinw, y * sinw, z * sinw, cosw);
        result.Normalize();

        return result;
        }

    static Quaternion FromAxisAngle_GRAD (float x, float y, float z, float w)
        {
        return FromAxisAngle (x, y, z, w / 180.0 * txPI);
        }

    Quaternion operator * (Quaternion b)
        {
        Quaternion r (w * b.x + x * b.w + y * b.z - z * b.y,
                      w * b.y + y * b.w + z * b.x - x * b.z,
                      w * b.z + z * b.w + x * b.y - y * b.x,
                      w * b.w - x * b.x - y * b.y - z * b.z);
        r.Normalize();
        return r;
        }

    void Normalize()
        {
        float len2 = x*x + y*y + z*z + w*w;

        if (len2 == 0.0) return;
        if (len2 == 1.0) return;

        float len = sqrtf (len2);
        x /= len;
        y /= len;
        z /= len;
        w /= len;
        }

    float Norm()
        {
        return x*x + y*y + z*z + w*w;
        }

    float Magnitude()
        {
        return sqrtf (x*x + y*y + z*z + w*w);
        }

    Quaternion Conjurate()
        {
        return Quaternion (-x, -y, -z, w);
        }

    float ScalarMultiply (Quaternion v)
        {
        return x * v.x + y * v.y + z * v.z + w * v.w;
        }

    Matrix ToMatrix()
        {
        Normalize();

        float s = 2.0;  // 4 mul 3 add 1 div

        float x2 = x * s,   y2 = y * s,   z2 = z * s,
              xx = x * x2,  xy = x * y2,  xz = x * z2,
              yy = y * y2,  yz = y * z2,  zz = z * z2,
              wx = w * x2,  wy = w * y2,  wz = w * z2;

        return Matrix (1.0f - (yy + zz), xy - wz, xz + wy, xy + wz,
                       1.0f - (xx + zz), yz - wx, xz - wy, yz + wx,
                       1.0f - (xx + yy));
        }
    };

Vector FindNearestIntersectionOfSphereAndLine (float x0, float y0, float z0,
                                               float x1, float y1, float z1,
                                               float x2, float y2, float z2,
                                               float r)
    {
    float dx = x1 - x0,
          dy = y1 - y0,
          dz = z1 - z0;

    float A  = dx*dx + dy*dy + dz*dz;
    float B  = 2 * x0 * dx + 2 * y0 * dy + 2 * z0 * dz;
    float C  = x0*x0 + y0*y0 + z0*z0 - r*r;

    // And the equation is A * t^2 + Bt + C = 0

    float D  = B*B - 4 * A * C;

    if (D < 0)
        return Vector (0, 0, 0);

    if (D > 0)
        {
        float d = sqrtf (D);
        float t1 = -B + d;
        float t2 = -B - d;

        Vector first  = Vector (x0, y0, z0) + ((Vector (x1, y1, z1) - Vector (x0, y0, z0)) * t2);
        Vector second = Vector (x0, y0, z0) + ((Vector (x1, y1, z1) - Vector (x0, y0, z0)) * t1);

        return (first.vz > second.vz)? second : first;
        }

    float t = -B / (2 * A);
    Vector thePoint = Vector (x0, y0, z0) + (Vector (x1, y1, z1) - Vector (x0, y0, z0)) * t;

    return thePoint;
    }

Vector Calculate3DMouseVector (float sphereRadius)
    {
    float mouseX = -(txMouseX() - 400.0) / 300.0,
          mouseY = -(txMouseY() - 300.0) / 300.0;

    float len2 = mouseX * mouseX + mouseY * mouseY;

    if (len2 > 1.0f)
        {
        float norm = 1.0 / sqrtf (len2);
        return Vector (mouseX / norm, mouseY / norm, 0);
        }
    else
        return Vector (mouseX, mouseY, sqrtf (1.0 - len2));
    }
