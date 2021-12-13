#include<drbip.h>
#include<SimpleBlinkyTypes.hpp>
#include<map>
#include<list>
#include<set>
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

        void insertLeft(Node *from, Node *newNode) {
            surfaces *s = blocks.find(from)->second;
            if(s->left) {
                printf("Left already connected");
                return;
            }
            s->left = (surfaces*) malloc(sizeof(surfaces));
            (s->left)->left = NULL;
            (s->left)->right = s;
            
            blocks.insert(pair<Node*, surfaces*>(newNode, s->left));
        }

        void insertRight(Node *from, Node *newNode) {
            surfaces *s = blocks.find(from)->second;
            if(s->right) {
                printf("Left already connected");
                return;
            }
            s->right = (surfaces*) malloc(sizeof(surfaces));
            (s->right)->left = s;
            (s->right)->right = NULL;
            
            blocks.insert(pair<Node*, surfaces*>(newNode, s->left));
        }

        void assign(BBMap * bbmap) {
            blocks.clear();
            blocks = bbmap->blocks;
        }

                //Direction: 1 left, 2 right, 3 top, 4 bottom, 5 front, 6 back
        bool isNeighbour(Node *n1, Node *n2, int direction) {
            if(n1 && n2) {
                switch (direction) {
                case 1:
                    (blocks.find(n1)->second->left == blocks.find(n2)->second ) ? true : false; 
                    break;
                
                case 2:
                    (blocks.find(n1)->second->right == blocks.find(n2)->second ) ? true : false; 
                    break;

                default:
                    return false;
                    break;
                }
            }
            return false;
        }

        //Direction: 1 left, 2 right, 3 top, 4 bottom, 5 front, 6 back
        bool hasNeighbour(Node *n, int direction) {
            if(!n) return false;

            switch (direction) {
            case 1:
                (blocks.find(n)->second->left != NULL) ? true : false; 
                break;
            case 2:
                (blocks.find(n)->second->right != NULL) ? true : false; 
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