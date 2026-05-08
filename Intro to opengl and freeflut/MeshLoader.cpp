#include "MeshLoader.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace MeshLoader
{
	Mesh* Load(char* path)
	{
		Mesh* mesh = new Mesh();

		ifstream inFile;
		inFile.open(path);

		if (!inFile.good())  
		{
			cerr << "Can't open texture file " << path << endl;
			delete mesh;
			return nullptr;
		}

		// Load Vertices
		inFile >> mesh->VertexCount;
		if (mesh->VertexCount > 0)
		{
			mesh->Vertices = new Vertex[mesh->VertexCount];
			for (int i = 0; i < mesh->VertexCount; i++)
			{
				inFile >> mesh->Vertices[i].x
					   >> mesh->Vertices[i].y
					   >> mesh->Vertices[i].z;
			}
		}

		// Load Colors
		inFile >> mesh->ColorCount;
		if (mesh->ColorCount > 0)
		{
			mesh->Colors = new Color[mesh->ColorCount];
			for (int i = 0; i < mesh->ColorCount; i++)
			{
				inFile >> mesh->Colors[i].r
					   >> mesh->Colors[i].g
					   >> mesh->Colors[i].b;
			}
		}

		// Read texture coordinate count
		inFile >> mesh->TexCoordCount;

		// Allocate and read each u,v pair
		mesh->TexCoords = new TexCoord[mesh->TexCoordCount];
		for (int i = 0; i < mesh->TexCoordCount; i++) 
		{
			inFile >> mesh->TexCoords[i].u;
			inFile >> mesh->TexCoords[i].v;
		}

		// Load Indices
		inFile >> mesh->IndexCount;
		if (mesh->IndexCount > 0)
		{
			mesh->Indices = new GLushort[mesh->IndexCount];
			for (int i = 0; i < mesh->IndexCount; i++)
			{
				inFile >> mesh->Indices[i];
			}
		}

		inFile.close();
		return mesh;
	}
}