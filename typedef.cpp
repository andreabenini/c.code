// Simple typedef usage
typedef map<const char*, ModuleItem> ModuleItemsList;

// Typedef class
typedef class ModuleMap {
    public:
        map<const char*, ModuleItemsList> Clients;
        ModuleMap()  {};
        ~ModuleMap() {};
} ModulesList; /**/

// Now I can use:
//     ModulesList MyOwnObject;
//     ModuleItemsList ListObj;
