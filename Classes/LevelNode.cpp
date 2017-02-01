//
//  LevelNode.ccp
//  SLOW
//
//  Created by Volodymyr Klymenko on 19.01.17
//
//

#include "LevelNode.h"


bool LevelNode::init() {
    
    if (!Node::init()) {
        return false;
    }
    
    return true;
}

LevelNode::LevelNode() {
    
}

LevelNode::~LevelNode() {
    
}
