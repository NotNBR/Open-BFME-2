// cl: /O2 /DNDEBUG /MD /GX- /Ob2
// stlport
// Adapted from BFME1 GeometryParseHeightAndMajorRadius.cpp.
// PC FieldParse C0EC00 identifies GeometryMajorRadius -> ABEA60.
// Same 24-byte shape vector at +2C; PC scanReal is a member, not static.
#include <vector>
class INI {
public:
    const char *getNextToken(const char *);
    float scanReal(const char *);
};
struct GeometryShape {
    int type; float height, majorRadius, minorRadius, x, y, z;
    char *name; bool active; char padding[3];
};
class GeometryInfo {
public:
    static void parseGeometryMajorRadius(INI *, void *, void *, const void *);
    void calcBoundingStuff();
    char head[0x2C];
    std::vector<GeometryShape> shapes;
};
void GeometryInfo::parseGeometryMajorRadius(INI *ini, void *, void *store, const void *) {
    GeometryInfo *geometry=(GeometryInfo *)store;
    if(geometry->shapes.size()!=0)
        geometry->shapes.back().majorRadius=ini->scanReal(ini->getNextToken(0));
    geometry->calcBoundingStuff();
}
