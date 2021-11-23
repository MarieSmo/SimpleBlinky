#include<drbip.h>
#include<SimpleBlinkyTypes.hpp>
#include<map>
#include<list>
#include<set>
using namespace SimpleBlinky;

namespace reconfigure {

    class NodeMCU : public CondState<AT__MCU, 0, -1> {
        public:
        NodeMCU(AT__MCU * atom) : CondState(atom) {}
    };

    class NodeSurfaces : public CondState<AT__SURFACES, 1, -1> {
        public:
        NodeSurfaces(AT__SURFACES * atom) : CondState(atom) {}
    };

    class SimpleBlinkyMap {
        private:
        AT__MCU * mcu;
        AT__SURFACES * surfaces;

        public:
        /*SimpleBlinkyMap(AT__MCU* i_mcu, AT__SURFACE* i_surface_left, AT__SURFACE* i_surface_right) {
            mcu = i_mcu;
            surface_left = i_surface_left;
            surface_right = i_surface_right;
        }*/

        void addMcu(AT__MCU * m) {
            mcu = m;
        }

        void addSurfaces(AT__SURFACES * s) {
            surfaces = s;
        }

        bool isTurnOn() {
            return mcu->_m__MCUSwitcher;
        }
    };

    //BlinkyBlock Map 
    class BBMap {
        public:
        list<Node*> blocks;

        Node * extend() {
            Node* newNode = new Node();
            blocks.push_back(newNode);
            return newNode;
        }

        void erase(Node * node) {
            auto it = blocks.begin();
            for(; it != blocks.end(); ++ it) {
                if((*it) == node)
                    break;
        }
            if(it == blocks.end())
                return;

            blocks.erase(it);
        }

        //Direction: 1 left (clockwise), 2 right (counter-clockwise)
        bool isNeighbour(Node *n1, Node *n2, int direction) {
            auto it = blocks.begin();
            for(; it != blocks.end(); ++ it)
                if((*it) == n1)
                    break;

            if(it == blocks.end())
                return false;

            if(direction == 1) {
                it++;
                if(it == blocks.end()) {
                    return *(blocks.begin()) == n2;
                }
                    else {
                    return *(it) == n2;
                }
            }
            else if(direction == 2) {
                if(it == blocks.begin())
                    return *(blocks.end()) == n2;
                else {
                    it--;
                    return *(it) == n2;
                }
            }

            return false;
        }

        void print() {
            cout << this << ":";
            for(auto elem = blocks.begin(); elem != blocks.end(); ++elem) {
                cout << " " << *elem;
            }
            cout << endl;
        }
    };
}