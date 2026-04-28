#include "MeshLoader.h"

#include <iostream>
#include <fstream>

using namespace std;

namespace MeshLoader
{
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadColours(ifstream& inFile, Mesh& mesh);
	void LoadIndices(ifstream& inFile, Mesh& mesh);

	void LoadVertices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.VertexCount;

		if (mesh.VertexCount > 0)
		{
			mesh.Vertices = new Vertex[mesh.VertexCount];

			for (int i = 0; i < mesh.VertexCount; i++)
			{
				inFile >> mesh.Vertices[i].x;
				inFile >> mesh.Vertices[i].y;
				inFile >> mesh.Vertices[i].z;
			}
		}
	}

	void LoadColours(ifstream& inFile, Mesh& mesh)
	{
		//TODO: LOAD COLOURS
	}

	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		//TODO: Load Indices
	}

	Mesh* MeshLoader::Load(char* path)
	{
		Mesh* mesh = new Mesh();

		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())  
		{
			cerr  << "Can't open texture file " << path << endl;
			return nullptr;
		}
		
		inFile >> numVertices;
		indexedVertices = new Vertex[numVertices];
		for (int i = 0; i < numVertices; i++)
		{
		    inFile >> indexedVertices[i].x
		           >> indexedVertices[i].y
		           >> indexedVertices[i].z;
		}
		
	    inFile >> numColors;
	    indexedColors = new Color[numColors];
	    for (int i = 0; i < numColors; i++)
	    {
	        inFile >> indexedColors[i].r
	               >> indexedColors[i].g
	               >> indexedColors[i].b;
	    }
			
		
			    inFile >> numIndices;
			    indices = new GLushort[numIndices];
			    for (int i = 0; i < numIndices; i++)
			    {
			        inFile >> indices[i];
			    }
			
			    inFile.close();
			    return true;
			 
		//LOAD DATA USING METHODS ABOVE

		return mesh;

		//s[;oitttt
				//    }
		//
		//    
		//
		//    /
	}
}