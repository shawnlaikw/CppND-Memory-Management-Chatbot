#include "graphedge.h"
#include "graphnode.h"

#include <iostream>
#include <memory>
GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    //delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
{   
    //std::unique_ptr<GraphEdge> t = *edge;
    //t=std::make_unique<GraphNode> ;    
    //;

    _childEdges.push_back(std::unique_ptr<GraphEdge> (edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{

    //_chatBot = &chatbot;
  
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
      //std::cout<<"6"<<std::endl;   
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    //newNode->MoveChatbotHere(_chatBot);
    newNode->MoveChatbotHere(std::move(_chatBot));
    //1_chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

   GraphEdge *t = _childEdges[index].get();

    return t;

    ////
    //// EOF STUDENT CODE
}