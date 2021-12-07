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

    class NodeSurfaces : public CondState<AT__SURFACES, 1, -1> {
        public:
        NodeSurfaces(AT__SURFACES * atom) : CondState(atom) {}
    };

    class SimpleBlinkyMap {
        public:
        Node * core;
        Node * surfaces;

        /*bool isAssembled(Node * core, Node * surfaces) {
            return surfaces->_m__isAssembled && core->_m__isAssembled;
        }*/

        /*SimpleBlinkyMap(AT__MCU* i_mcu, AT__SURFACE* i_surface_left, AT__SURFACE* i_surface_right) {
            mcu = i_mcu;
            surface_left = i_surface_left;
            surface_right = i_surface_right;
        }*/

        Node * addCore() {
            Node* newNode = new Node();
            core = newNode;
            return newNode;
        }

        Node * addSurfaces() {
            Node* newNode = new Node();
            surfaces = newNode;
            return newNode;
        }

        void eraseCore() {
            core = NULL;
        }

        void eraseSurfaces() {
            surfaces = NULL;
        }
    };

    //BlinkyBlock Map 
    class BBMap {
        private:
        typedef struct surface {
            struct surface *left;
            struct surface *right;
            struct surface *top;
            struct surface *bottom;
            struct surface *front;
            struct surface *back;
        } surfaces;

        surfaces * initSurfaces() {
            surfaces *l = new surfaces;
            l->left = NULL;
            l->right = NULL;
            l->top = NULL;
            l->bottom = NULL;
            l->front = NULL;
            l->back = NULL;
            return l;
        }

        public:
        map<Node*, surfaces*> blocks;

        Node * initialize() {
            Node* newNode = new Node();
            blocks.insert(pair<Node*, surfaces*>(newNode, initSurfaces()));
            return newNode;
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
            (s->left)->top = NULL;
            (s->left)->bottom = NULL;
            (s->left)->front = NULL;
            (s->left)->back = NULL;
            
            blocks.insert(pair<Node*, surfaces*>(newNode, s->left));
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

                case 3:
                (blocks.find(n1)->second->top == blocks.find(n2)->second ) ? true : false; 
                    break;

                case 4:
                    (blocks.find(n1)->second->bottom == blocks.find(n2)->second ) ? true : false; 
                    break;
                
                case 5:
                    (blocks.find(n1)->second->front == blocks.find(n2)->second ) ? true : false; 
                    break;
                
                case 6:
                    (blocks.find(n1)->second->back == blocks.find(n2)->second ) ? true : false; 
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
            case 3:
                (blocks.find(n)->second->top != NULL) ? true : false; 
                break;
            case 4:
                (blocks.find(n)->second->bottom != NULL) ? true : false; 
                break;
            case 5:
                (blocks.find(n)->second->front != NULL) ? true : false; 
                break;
            case 6:
                (blocks.find(n)->second->back != NULL) ? true : false; 
                break;
            default:
                return false;
                break;
            }
        }
    };
}