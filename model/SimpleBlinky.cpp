#include <drbip.h>
#include <SimpleBlinkyTypes.hpp>
#include <map>
#include <list>
#include <set>
#include <stdlib.h>
#include <stdio.h>
#include "ext.cpp"

using namespace SimpleBlinky;

namespace reconfigure {

    /**
     * @brief The following classes are some atomic component in BIP. These classes are generated through DR-BIP compilation.
     */
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

    /**
     * @brief This DR-BIP reconfiguration map is used to assemble all component in atomic form of a Blincky Block.
     * In fact it represent one and only one blinky.
     * It correspond to a compound in BIP, but as it is not possible to use compound in DR-BIP, we have to represent it as a map.
     */
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

        int getCoreId(AT__CORE *core) {
            return core->_param__id;
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

    /**
     * @brief The BBMap class (Blinky Block Map) is the shape created by a fixed number of blinky given in DR-BIP.
     * It used a Core (from BIP atom) in Node format.
     * The surfaces here are abstract and are not directly link to the surface atom of BIP. They are used as rule in DR-BIP to ensure that
     * two block will not be connected again on a same surface. It is also used to avoid physical impossible connection such as two surfaces on a block b1 
     * connected to two other surfaces on a block b2.
     */
    class BBMap {
        private:
        typedef struct surface {
            struct surface *left;
            struct surface *right;
        } surfaces;

        surfaces * initSurfaces() {
            surfaces *s = new surfaces;
            s->left = NULL;
            s->right = NULL;
            return s;
        }

        public:
        //Blocks are represented so far with a Node Core and a structure surfaces (represente all surfaces of a block)
        map<Node*, surfaces*> blocks;

        Node * create() {
            return new Node();
        }

        ~BBMap() {
            blocks.clear();
        }

        /**
         * @brief Insert a new block in the map
         * 
         * @param node The node is a Core in BIP in node-format. The surfaces here are not directly linked to BIP, but are more abstract
         */
        void insertCore(Node * node) {
            blocks.insert(pair<Node*, surfaces*>(node, initSurfaces()));
        }

        /**
         * @brief Used to connect two block between each other
         * In this specific case, connect the first block on the left with the second block on the right surface
         * 
         * @param left The block (represent by a Core in node form) where left surface is connected
         * @param right The block (represent by a Core in node form) where right surface is connected
         */
        void connectLeft(Node *left, Node *right) {
            surfaces * bsLeft = blocks.find(left)->second; // Surfaces of left block
            surfaces * bsRight = blocks.find(right)->second; // Surfaces of right block

            bsLeft->left = bsRight; // Left surface of left block connected to right surface of right block
            bsRight->right = bsLeft; // Right surface of right block connected to left surface of left block
        }

        void printConnection(AT__CORE* b1, int d1, AT__CORE* b2, int d2) {
            printf("\033[32m[Connection]:\033[0m Surface \033[33m%s\033[0m from \033[33mblock %d\033[0m connected to surface \033[33m%s\033[0m from \033[33mblock %d\033[0m\n", connection(d1), b1->_param__id, connection(d2), b2->_param__id);
        }

        void assign(BBMap * bbmap) {
            blocks.clear();
            blocks = bbmap->blocks;
        }

        /**
         * @brief Check if two core in the BBMap shape are neighboor or not
         * 
         * @param n1 Core of the first block in the map
         * @param n2 Core of the second block in the map
         * @param direction Used to search if n1 is left (or right, or top...) neighboor of n2.
         *  Direction: 1 left, 2 right, 3 top, 4 bottom, 5 front, 6 back
         * @return true --- If n1 and n2 are neighboor in the given direction
         * @return false --- If n1 and n2 are not neighboor
         */
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

        /**
         * @brief Check if two core are already connected between each other (Check all surface if a connection exist)
         * 
         * @param n1 First core in the map
         * @param n2 Second core in the map
         * @return true --- If they are connected
         * @return false --- If they are not connected
         */
        bool isAlrdeadyConnected(Node *n1, Node *n2) {
            if(blocks.find(n1)->second->left == blocks.find(n2)->second) return true;
            if(blocks.find(n1)->second->right == blocks.find(n2)->second) return true;
            return false;
        }

        /**
         * @brief Chek if a surface in BIP is connected or not to another surfaces
         * 
         * @param s The surface
         * @return true -- If it is connected to another surface
         * @return false -- If it is not connected to anything
         */
        bool isSurfaceFreeToUse(AT__SURFACE *s) {
            cout<<"\n---- SURFACE --- "<< (bool)(!s->_m__isConnected)<<"\n";
            return !s->_m__isConnected;
        }

        /**
         * @brief Chek if the core is well asssemble in BIP
         * 
         * @param c The core
         * @return true -- The block is assemble
         * @return false -- The block is disassemble
         */
        bool isAssemble(AT__CORE *c) {
            cout<<"\n--- CORE ---- "<<(bool)(c->_m__isAssembled)<<"\n";
            return c->_m__isAssembled;
        }

        /**
         * @brief Check if a core has a potantial neighboor 
         * 
         * @param node The core (As a node in the map) -- Used for all calcul
         * @param core The core (As an BIP atom) -- Used to get the core ID in the print
         * @param direction Used to search a neighboor in a specific direction
         * Direction: 1 left, 2 right, 3 top, 4 bottom, 5 front, 6 back
         * @return true 
         * @return false 
         */
        bool hasNeighbour(Node *node, AT__CORE* core, int direction) {
            if(!node) return false;
            surfaces *surface = blocks.find(node)->second;

            switch (direction) {
            case 1:
                if(surface->left) {
                    //printf("\033[32m[Output]:\033[0m Surface \033[33mleft\033[0m from \033[33mblock %d\033[0m already connected\n", core->_param__id);
                    return true;
                }
                //printf("\033[32m[Output]:\033[0m Surface \033[33mleft\033[0m from \033[33mblock %d\033[0m not yet connected\n", core->_param__id);
                return false;
                break;
            case 2:
                if(surface->right) {
                    //printf("\033[32m[Output]:\033[0m Surface \033[33mright\033[0m from \033[33mblock %d\033[0m already connected\n", core->_param__id);
                    return true;
                }
                //printf("\033[32m[Output]:\033[0m Surface \033[33mright\033[0m from \033[33mblock %d\033[0m not yet connected\n", core->_param__id);
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