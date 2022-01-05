#include <drbip.h>
#include <SimpleBlinkyTypes.hpp>
#include <map>
#include <list>
#include <set>
#include <stdlib.h>
#include <stdio.h>

using namespace SimpleBlinky;

namespace reconfigure {

    class NodeCore : public CondState<AT__CORE, 0, -1> {
        public:
        NodeCore(AT__CORE * atom) : CondState(atom) {}
    };

    class NodeSurfaceLeft : public CondState<AT__SURFACE, 1, -1> {
        public:
        NodeSurfaceLeft(AT__SURFACE * atom) : CondState(atom) {}
    };

    class NodeSurfaceRight : public CondState<AT__SURFACE, 2, -1> {
        public:
        NodeSurfaceRight(AT__SURFACE * atom) : CondState(atom) {}
    };

    class SimpleBlinkyMap {
        public:
        Node * core;
        Node * surface_left;
        Node * surface_right;

        Node * create() {
            return new Node();
        }
        
        void setCore(Node * c) {
            this->core = c;
        }

        void setSurfaceLeft(Node * s) {
            this->surface_left = s;
        }

        void setSurfaceRight(Node * s) {
            this->surface_right = s;
        }

        Node * getCore() {
            return core;
        }

        Node * getLeft() {
            return surface_left;
        }

        Node * getRight() {
            return surface_right;
        }

        bool isCore(Node * node) {
            return node == core;
        }

        bool isLeft(Node * node) {
            return node == surface_left;
        }

        bool isRight(Node * node) {
            return node == surface_right;
        }

        ~SimpleBlinkyMap() {
            delete core;
            delete surface_left;
            delete surface_right;
        }
    };

    //BlinkyBlock Map 
    class BBMap {
        private:
        typedef struct surface {
            struct surface *left;
            struct surface *right;
        } surfaces;

        surfaces * initSurfaces() {
            surfaces *l = new surfaces;
            l->left = NULL;
            l->right = NULL;
            return l;
        }

        public:
        map<Node*, surfaces*> blocks;

        Node * create() {
            return new Node();
        }

        void insertCore(Node * node) {
            blocks.insert(pair<Node*, surfaces*>(node, initSurfaces()));
        }

        void connectLeft(Node *left, Node *right) {
            surfaces * sLeft = blocks.find(left)->second;
            surfaces * sRight = blocks.find(right)->second;

            sLeft->left = sRight;
            sRight->right = sLeft;
        }

        /*void connectRight(Node *right, Node *left) {
            connectLeft(left, right);    
        }*/

        void assign(BBMap * bbmap) {
            blocks.clear();
            blocks = bbmap->blocks;
        }

        //Direction: 1 left, 2 right, 3 top, 4 bottom, 5 front, 6 back
        bool isNeighbour(Node *n1, Node *n2, int direction) {
            if(n1 && n2) {
                switch (direction) {
                case 1:
                    return blocks.find(n1)->second->left == blocks.find(n2)->second;
                    break;
                
                case 2:
                    return blocks.find(n1)->second->right == blocks.find(n2)->second; 
                    break;

                default:
                    return false;
                    break;
                }
            }
            return false;
        }

        bool isAlrdeadyConnected(Node *n1, Node *n2) {
            if(blocks.find(n1)->second->left == blocks.find(n2)->second) return true;
            if(blocks.find(n1)->second->right == blocks.find(n2)->second) return true;
            return false;
        }

        //Direction: 1 left, 2 right, 3 top, 4 bottom, 5 front, 6 back
        bool hasNeighbour(Node *node, AT__CORE* core, int direction) {
            if(!node) return false;
            surfaces *surface = blocks.find(node)->second;

            switch (direction) {
            case 1:
                if(surface->left) {
                    printf("\033[32m[Output]:\033[0m Surface \033[33mleft\033[0m from \033[33mblock %d\033[0m already connected\n", core->_param__id);
                    return true;
                }
                printf("\033[32m[Output]:\033[0m Surface \033[33mleft\033[0m from \033[33mblock %d\033[0m not yet connected\n", core->_param__id);
                return false;
                break;
            case 2:
                if(surface->right) {
                    printf("\033[32m[Output]:\033[0m Surface \033[33mright\033[0m from \033[33mblock %d\033[0m already connected\n", core->_param__id);
                    return true;
                }
                printf("\033[32m[Output]:\033[0m Surface \033[33mright\033[0m from \033[33mblock %d\033[0m not yet connected\n", core->_param__id);
                return false;
                break;
            default:
                return false;
                break;
            }
        }
    };

    class BBAddressing {
        public:
        map<AtomType*, Node*> nodeMap;

        void bind(AtomType* atom, Node* node) {
            nodeMap.insert(pair<AtomType*, Node*>(atom, node));
        }

        Node * operator()(AtomType * atom) {
            auto value = nodeMap.find(atom);
            if(value != nodeMap.end())
                return value->second;
            else
                return NULL;
        }
    };
}