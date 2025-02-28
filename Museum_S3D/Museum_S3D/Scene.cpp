﻿#include "Scene.h"
#include "Camera.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Model.h"
#include <map>
#include <string>

		Renderer * renderer;
	Renderer * renderPodium;

	map<std::string, Model>*models;
	//AABB BOXES


	Scene::Scene(GLuint width, GLuint height) :
		Width(width), Height(height)
	{

	}

	Scene::~Scene()
	{
		delete renderer;
	}

	void Scene::Init()
	{
		//Shaders
		ResourceManager::LoadShader("Floor.vs", "Floor.fs", "shaderFloor");

		//Textures
		ResourceManager::LoadTexture("../../Textures/floor.jpg", "floorTexture");
		ResourceManager::LoadTexture("../../Textures/wall.jpg", "wallTexture");
		ResourceManager::LoadTexture("../../Textures/Ceiling.png", "ceilingTexture");
		ResourceManager::LoadTexture("../../Textures/grassTexture.jpg", "grassTexture");
		ResourceManager::LoadTexture("../../Textures/muzeu.jpg", "museumTexture");
		ResourceManager::LoadTexture("../../Textures/door.jpg", "doorTexture");
		ResourceManager::LoadTexture("../../Textures/bugs.jpg", "bugs");
		ResourceManager::LoadTexture("../../Textures/dragonfly.jpg", "dragonfly");
		ResourceManager::LoadTexture("../../Textures/Spiders.jpg", "spiders");
		ResourceManager::LoadTexture("../../Textures/columnTexture.jpg", "columnsTexture");
		ResourceManager::LoadTexture("../../Textures/redCarpet.jpg", "redCarpet");
		ResourceManager::LoadTexture("../../Textures/forest.jpeg", "forest");

		//Info about animals
		ResourceManager::LoadTexture("../../Textures/bearinfo.png", "bearinfo");
		ResourceManager::LoadTexture("../../Textures/wolfinfo.png", "wolfinfo");
		ResourceManager::LoadTexture("../../Textures/spinosaurusInfo.png", "spinosaurusInfo");
		ResourceManager::LoadTexture("../../Textures/barosaurusInfo.png", "barosaurusInfo");
		ResourceManager::LoadTexture("../../Textures/dilophosaurusInfo.png", "dilophosaurusInfo");
		ResourceManager::LoadTexture("../../Textures/quetzalcoatlusInfo.png", "quetzalcoatlusInfo");

		ResourceManager::LoadTexture("../../Textures/Daisy.jpg", "Daisy");
		ResourceManager::LoadTexture("../../Textures/Rose.jpg", "Rose");
		ResourceManager::LoadTexture("../../Textures/Tulip.jpg", "Tulip");
		ResourceManager::LoadTexture("../../Textures/Daffodil.jpg", "Daffodil");

		ResourceManager::LoadTexture("../../Textures/picture1.jpg", "picture1");
		ResourceManager::LoadTexture("../../Textures/picture2.jpg", "picture2");
		ResourceManager::LoadTexture("../../Textures/picture3.jpg", "picture3");
		ResourceManager::LoadTexture("../../Textures/picture4.jpg", "picture4");
	

		models = new map<std::string, Model>();
		//MODELS

		//Mountain/forest zone
		models->insert({ "Wolf",Model("../../3DObjects/Wolf/wolf.obj") });
		models->insert({ "Tree",Model("../../3DObjects/Tree/Tree.obj") });
		models->insert({ "Spinosaurus", Model("../../3DObjects/Spinosaurus/spinosaurus.obj") });
		models->insert({ "Quetzalcoatlus", Model("../../3DObjects/Quetzalcoatlus/13623_Quetzalcoatlus_v1_L2.obj") });
		models->insert({ "Wire", Model("../../3DObjects/Wire/wire.obj") });
		models->insert({ "Dilophosaurus", Model("../../3DObjects/Dilophosaurus/dilophosaurus.obj") });
		models->insert({ "Barosaurus", Model("../../3DObjects/Barosaurus/21534_Barosaurus_v1.obj") });
		models->insert({ "Bear", Model("../../3DObjects/Bear/Bear.obj") });
		models->insert({ "Cearadactylus", Model("../../3DObjects/Cearadactylus/13627_Cearadactylus_v2_l3.obj") });
		models->insert({ "Vultur", Model("../../3DObjects/Vultur/Vultur.obj") });
		models->insert({ "Grass",Model("../../3DObjects/Grass/Grass.obj") });
		models->insert({ "Podium",Model("../../3DObjects/Podium/podium.obj") });
		models->insert({ "Oak Tree",Model("../../3DObjects/Oak Tree/10445_Oak_Tree_v1_max2010_iteration-1.obj") });
		models->insert({ "Daisy",Model("../../3DObjects/Plants/Daisy/10441_Daisy_v1_max2010_iteration-2.obj") });
		models->insert({ "Rose",Model("../../3DObjects/Plants/Rose/rose.obj") });
		models->insert({ "Tulip",Model("../../3DObjects/Plants/Tulip/12978_tulip_flower_l3.obj") });
		models->insert({ "Daffodil",Model("../../3DObjects/Plants/Daffodil/12977_Daffodil_flower_v1_l2.obj") });
		models->insert({ "Crocus",Model("../../3DObjects/Plants/Crocus/12974_crocus_flower_v1_l3.obj") });
		models->insert({ "Anemone",Model("../../3DObjects/Plants/Anemone/12973_anemone_flower_v1_l2.obj") });
		models->insert({ "Light",Model("../../3DObjects/Light/light.obj") });
		models->insert({ "Pedastal",Model("../../3DObjects/Pedastal/pedastal.obj") });
		models->insert({ "Parrot",Model("../../3DObjects/Parrot/parrot.obj") });
		models->insert({ "Stork",Model("../../3DObjects/Stork/stork.obj") });
		models->insert({ "Pelican",Model("../../3DObjects/Pelican/pelican.obj") });
		models->insert({ "Duck",Model("../../3DObjects/Duck/duck.obj") });
		models->insert({ "Skull_Dino",Model("../../3DObjects/Skull_Dino/13638_Tyrannosaurus_Rex_Skull_Fossil_v1_L1.obj") });
		models->insert({ "Human",Model("../../3DObjects/Human/Style human obj.obj") });
		models->insert({ "Counter",Model("../../3DObjects/Counter/counter.obj") });
		models->insert({ "Statue",Model("../../3DObjects/Statue/10081_Park-Statue_V3_L3.obj") });
		models->insert({ "Pedastal2",Model("../../3DObjects/Pedastal2/pedastal2.obj") });
		models->insert({ "Fish1",Model("../../3DObjects/Fish Models/Fish1/12265_Fish_v1_L2.obj") });
		models->insert({ "Fish2",Model("../../3DObjects/Fish Models/Fish2/13007_Blue-Green_Reef_Chromis_v2_l3.obj") });
		models->insert({ "Fish3",Model("../../3DObjects/Fish Models/Fish3/12999_Boesemani_Rainbow_v1_l2.obj") });
		models->insert({ "Fish4",Model("../../3DObjects/Fish Models/Fish4/13016_Yellowtai_ Damselfish_v2_l3.obj") });
		models->insert({ "Fish5",Model("../../3DObjects/Fish Models/Fish5/12988_Electric_Yellow_cichlid_v1_l3.obj") });
		models->insert({ "Horse",Model("../../3DObjects/Horse/10026_Horse_v01-it2.obj") });
		models->insert({ "Cat",Model("../../3DObjects/Cat/12161_Cat_v1_L2.obj") });

		//Renderers
		renderer = new Renderer(ResourceManager::GetShader("shaderFloor"));
		renderPodium = new Renderer(ResourceManager::GetShader("shaderFloor"), true);
	}

	void Scene::SetCamera(Camera * camera)
	{
		pCamera = camera;
	}

	float rotationAngle = 0.0f;

	void Scene::Render()
	{
		// FIRST ROOM
		renderer->Draw(ResourceManager::GetTexture("floorTexture"), pCamera, glm::vec3(-50.0f, 0.f, 0.f), glm::vec3(), 0.f, glm::vec3(), NULL);

		renderer->Draw(ResourceManager::GetTexture("wallTexture"), pCamera, glm::vec3(-50.f, 4.5f + resize, -4.5f - resize), glm::vec3(), glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f), NULL);
		renderer->Draw(ResourceManager::GetTexture("wallTexture"), pCamera, glm::vec3(-50.f, 4.5f + resize, 5.5f + resize), glm::vec3(), glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f), NULL);
		renderer->Draw(ResourceManager::GetTexture("wallTexture"), pCamera, glm::vec3(-95.5f + resize, 4.5f + resize, 0.f), glm::vec3(), glm::radians(90.f), glm::vec3(0.f, 0.f, 1.f), NULL);
		renderer->Draw(ResourceManager::GetTexture("ceilingTexture"), pCamera, glm::vec3(-50.f, 30.f + resize, 0.f), glm::vec3(), 0.f, glm::vec3(0.f, 0.f, 1.f), NULL);


		renderer->Draw(ResourceManager::GetTexture("doorTexture"), pCamera, glm::vec3(-45.209f + resize, 9.55f, 0.f), glm::vec3(0.3f, 0.4f, 0.4f), glm::radians(90.f), glm::vec3(0.f, 0.f, 1.f), 'z');
		renderer->Draw(ResourceManager::GetTexture("doorTexture"), pCamera, glm::vec3(-50.f, 9.55f, 4.79f + resize), glm::vec3(0.3f, 0.4f, 0.4f), glm::radians(-90.f), glm::vec3(1.f, 0.f, 0.f), NULL);
		// SECOND ROOM
		renderer->Draw(ResourceManager::GetTexture("floorTexture"), pCamera, glm::vec3(), glm::vec3(), 0.f, glm::vec3(), NULL);

		renderer->Draw(ResourceManager::GetTexture("wallTexture"), pCamera, glm::vec3(0.f, 4.5f + resize, -4.5f - resize), glm::vec3(), glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f), NULL);
		renderer->Draw(ResourceManager::GetTexture("wallTexture"), pCamera, glm::vec3(0.f, 4.5f + resize, 5.5f + resize), glm::vec3(), glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f), NULL);
		renderer->Draw(ResourceManager::GetTexture("wallTexture"), pCamera, glm::vec3(4.5f + resize, 4.5f + resize, 0.f), glm::vec3(), glm::radians(90.f), glm::vec3(0.f, 0.f, 1.f), NULL);
		renderer->Draw(ResourceManager::GetTexture("wallTexture"), pCamera, glm::vec3(-5.5f - resize, 4.5f + resize, 0.f), glm::vec3(), glm::radians(90.f), glm::vec3(0.f, 0.f, 1.f), NULL);

		renderer->Draw(ResourceManager::GetTexture("ceilingTexture"), pCamera, glm::vec3(0.f, 30.f + resize, 0.f), glm::vec3(), 0.f, glm::vec3(0.f, 0.f, 1.f), NULL);

		renderer->Draw(ResourceManager::GetTexture("museumTexture"), pCamera, glm::vec3(0.f, 8.f + resize, -3.4f - resize), glm::vec3(0.6f, 0.8f, 0.4f), glm::radians(270.f), glm::vec3(1.f, 0.f, 0.f), NULL);

		renderer->Draw(ResourceManager::GetTexture("doorTexture"), pCamera, glm::vec3(4.77f + resize, 9.55f, 0.f), glm::vec3(0.3f, 0.4f, 0.4f), glm::radians(90.f), glm::vec3(0.f, 0.f, 1.f), 'z');
		renderer->Draw(ResourceManager::GetTexture("doorTexture"), pCamera, glm::vec3(-5.185f - resize, 9.55f, 0.f), glm::vec3(0.3f, 0.4f, 0.4f), glm::radians(90.f), glm::vec3(0.f, 0.f, 1.f), 'z');
		renderer->Draw(ResourceManager::GetTexture("doorTexture"), pCamera, glm::vec3(-0.5f, 9.55f, 4.79f + resize), glm::vec3(0.3f, 0.4f, 0.4f), glm::radians(-90.f), glm::vec3(1.f, 0.f, 0.f), NULL);

		renderer->Draw(ResourceManager::GetTexture("redCarpet"), pCamera, glm::vec3(0.f, -0.43f, -20.5f + resize), glm::vec3(1.f, 0.1f, 0.25f), glm::radians(0.f), glm::vec3(1.f, 0.f, 0.f), NULL);
		renderer->Draw(ResourceManager::GetTexture("redCarpet"), pCamera, glm::vec3(0.f, -0.43f, -4.63f + resize), glm::vec3(0.385f, 0.1f, 0.25f), glm::radians(90.f), glm::vec3(0.f, 1.f, 0.f), NULL);
		renderer->Draw(ResourceManager::GetTexture("redCarpet"), pCamera, glm::vec3(0.f, -0.43f, -30.2f + resize), glm::vec3(0.14f, 0.1f, 0.25f), glm::radians(90.f), glm::vec3(0.f, 1.f, 0.f), NULL);

		// THIRD ROOM
		renderer->Draw(ResourceManager::GetTexture("floorTexture"), pCamera, glm::vec3(50.0f, 0.f, 0.f), glm::vec3(), 0.f, glm::vec3(), NULL);

		renderer->Draw(ResourceManager::GetTexture("wallTexture"), pCamera, glm::vec3(50.f, 4.5f + resize, -4.5f - resize), glm::vec3(), glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f), NULL);
		renderer->Draw(ResourceManager::GetTexture("wallTexture"), pCamera, glm::vec3(50.f, 4.5f + resize, 5.5f + resize), glm::vec3(), glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f), NULL);
		renderer->Draw(ResourceManager::GetTexture("wallTexture"), pCamera, glm::vec3(54.5f + resize, 4.5f + resize, 0.f), glm::vec3(), glm::radians(90.f), glm::vec3(0.f, 0.f, 1.f), NULL);

		renderer->Draw(ResourceManager::GetTexture("ceilingTexture"), pCamera, glm::vec3(50.f, 30.f + resize, 0.f), glm::vec3(), 0.f, glm::vec3(0.f, 0.f, 1.f), NULL);

		renderer->Draw(ResourceManager::GetTexture("doorTexture"), pCamera, glm::vec3(44.87f - resize, 9.55f, 0.f), glm::vec3(0.3f, 0.4f, 0.4f), glm::radians(90.f), glm::vec3(0.f, 0.f, 1.f), 'z');
		renderer->Draw(ResourceManager::GetTexture("doorTexture"), pCamera, glm::vec3(48.f, 9.55f, 4.7f + resize), glm::vec3(0.3f, 0.4f, 0.4f), glm::radians(-90.f), glm::vec3(1.f, 0.f, 0.f), NULL);

		renderer->Draw(ResourceManager::GetTexture("quetzalcoatlusInfo"), pCamera, glm::vec3(35.f, 13.f, -45.f + resize), glm::vec3(0.2f, 0.3f, 0.25f), glm::radians(-90.f), glm::vec3(1.f, 0.f, 0.f), NULL);
		renderer->Draw(ResourceManager::GetTexture("spinosaurusInfo"), pCamera, glm::vec3(50.f, 18.f, -45.f + resize), glm::vec3(0.2f, 0.3f, 0.25f), glm::radians(-90.f), glm::vec3(1.f, 0.f, 0.f), NULL);
		renderer->Draw(ResourceManager::GetTexture("dilophosaurusInfo"), pCamera, glm::vec3(65.f, 13.f, -45.f + resize), glm::vec3(0.2f, 0.3f, 0.25f), glm::radians(-90.f), glm::vec3(1.f, 0.f, 0.f), NULL);

		// SIXTH ROOM
		renderer->Draw(ResourceManager::GetTexture("floorTexture"), pCamera, glm::vec3(-50.0f, 0.f, 50.f), glm::vec3(), 0.f, glm::vec3(), NULL);

		renderer->Draw(ResourceManager::GetTexture("wallTexture"), pCamera, glm::vec3(-50.f, 4.5f + resize, 45.5f - resize), glm::vec3(), glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f), NULL);
		renderer->Draw(ResourceManager::GetTexture("wallTexture"), pCamera, glm::vec3(-50.f, 4.5f + resize, 55.5f + resize), glm::vec3(), glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f), NULL);
		renderer->Draw(ResourceManager::GetTexture("wallTexture"), pCamera, glm::vec3(-95.5f + resize, 4.5f + resize, 50.f), glm::vec3(), glm::radians(90.f), glm::vec3(0.f, 0.f, 1.f), NULL);

		renderer->Draw(ResourceManager::GetTexture("ceilingTexture"), pCamera, glm::vec3(-50.f, 30.f + resize, 50.f), glm::vec3(), 0.f, glm::vec3(0.f, 0.f, 1.f), NULL);

		renderer->Draw(ResourceManager::GetTexture("doorTexture"), pCamera, glm::vec3(5.271f + resize, 9.55f, 50.f), glm::vec3(0.3f, 0.4f, 0.4f), glm::radians(270.f), glm::vec3(0.f, 0.f, 1.f), 'z');
		renderer->Draw(ResourceManager::GetTexture("doorTexture"), pCamera, glm::vec3(48.f, 9.55f, 4.812f + resize), glm::vec3(0.3f, 0.4f, 0.4f), glm::radians(-90.f), glm::vec3(1.f, 0.f, 0.f), NULL);

		renderer->Draw(ResourceManager::GetTexture("Daisy"), pCamera, glm::vec3(75.2f, 17.5f, 20 + resize), glm::vec3(0.18f, 0.55f, 0.25f), glm::radians(-90.f), glm::vec3(0.f, 0.f, 1.f), 'z');
		renderer->Draw(ResourceManager::GetTexture("Rose"), pCamera, glm::vec3(75.2f, 17.5f, 40.f + resize), glm::vec3(0.18f, 0.55f, 0.25f), glm::radians(-90.f), glm::vec3(0.f, 0.f, 1.f), 'z');
		renderer->Draw(ResourceManager::GetTexture("Tulip"), pCamera, glm::vec3(57.5f, 17.5f, 54.6f + resize), glm::vec3(0.18f, 0.55f, 0.25f), glm::radians(90.f), glm::vec3(-1.f, 0.f, 0.f), NULL);
		renderer->Draw(ResourceManager::GetTexture("Daffodil"), pCamera, glm::vec3(37.5f, 17.5f, 54.6f + resize), glm::vec3(0.18f, 0.55f, 0.25f), glm::radians(90.f), glm::vec3(-1.f, 0.f, 0.f), NULL);

		// FIFTH ROOM
		renderer->Draw(ResourceManager::GetTexture("floorTexture"), pCamera, glm::vec3(0.0f, 0.f, 50.f), glm::vec3(), 0.f, glm::vec3(), NULL);

		renderer->Draw(ResourceManager::GetTexture("wallTexture"), pCamera, glm::vec3(0.f, 4.5f + resize, 45.5f - resize), glm::vec3(), glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f), NULL);
		renderer->Draw(ResourceManager::GetTexture("wallTexture"), pCamera, glm::vec3(0.f, 4.5f + resize, 55.5f + resize), glm::vec3(), glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f), NULL);
		renderer->Draw(ResourceManager::GetTexture("wallTexture"), pCamera, glm::vec3(-45.5f + resize, 4.5f + resize, 50.f), glm::vec3(), glm::radians(90.f), glm::vec3(0.f, 0.f, 1.f), NULL);

		renderer->Draw(ResourceManager::GetTexture("ceilingTexture"), pCamera, glm::vec3(0.f, 30.f + resize, 50.f), glm::vec3(), 0.f, glm::vec3(0.f, 0.f, 1.f), NULL);

		renderer->Draw(ResourceManager::GetTexture("doorTexture"), pCamera, glm::vec3(4.73f + resize, 9.55f, 50.f), glm::vec3(0.3f, 0.4f, 0.4f), glm::radians(90.f), glm::vec3(0.f, 0.f, 1.f), 'z');
		renderer->Draw(ResourceManager::GetTexture("doorTexture"), pCamera, glm::vec3(-45.1f + resize, 9.55f, 50.f), glm::vec3(0.3f, 0.4f, 0.4f), glm::radians(90.f), glm::vec3(0.f, 0.f, 1.f), 'z');
		renderer->Draw(ResourceManager::GetTexture("doorTexture"), pCamera, glm::vec3(-0.2f, 9.55f, 4.815f + resize), glm::vec3(0.3f, 0.4f, 0.4f), glm::radians(-90.f), glm::vec3(1.f, 0.f, 0.f), NULL);

		// FOURTH ROOM
		renderer->Draw(ResourceManager::GetTexture("floorTexture"), pCamera, glm::vec3(50.0f, 0.f, 50.f), glm::vec3(), 0.f, glm::vec3(), NULL);

		renderer->Draw(ResourceManager::GetTexture("wallTexture"), pCamera, glm::vec3(50.f, 4.5f + resize, 45.5f - resize), glm::vec3(), glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f), NULL);
		renderer->Draw(ResourceManager::GetTexture("wallTexture"), pCamera, glm::vec3(50.f, 4.5f + resize, 55.5f + resize), glm::vec3(), glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f), NULL);
		renderer->Draw(ResourceManager::GetTexture("wallTexture"), pCamera, glm::vec3(4.5f + resize, 4.5f + resize, 50.f), glm::vec3(), glm::radians(90.f), glm::vec3(0.f, 0.f, 1.f), NULL);
		renderer->Draw(ResourceManager::GetTexture("wallTexture"), pCamera, glm::vec3(54.5f + resize, 4.5f + resize, 50.f), glm::vec3(), glm::radians(90.f), glm::vec3(0.f, 0.f, 1.f), NULL);

		renderer->Draw(ResourceManager::GetTexture("ceilingTexture"), pCamera, glm::vec3(50.f, 30.f + resize, 50.f), glm::vec3(), 0.f, glm::vec3(0.f, 0.f, 1.f), NULL);

		renderer->Draw(ResourceManager::GetTexture("doorTexture"), pCamera, glm::vec3(-45.25f + resize, 9.55f, 50.f), glm::vec3(0.3f, 0.4f, 0.4f), glm::radians(90.f), glm::vec3(0.f, 0.f, 1.f), 'z');
		renderer->Draw(ResourceManager::GetTexture("doorTexture"), pCamera, glm::vec3(-50.f, 9.55f, 4.81f + resize), glm::vec3(0.3f, 0.4f, 0.4f), glm::radians(-90.f), glm::vec3(1.f, 0.f, 0.f), NULL);

		renderer->Draw(ResourceManager::GetTexture("picture1"), pCamera, glm::vec3(-40.5f, 17.5f, 54.6f + resize), glm::vec3(0.18f, 0.55f, 0.25f), glm::radians(90.f), glm::vec3(-1.f, 0.f, 0.f), NULL);
		renderer->Draw(ResourceManager::GetTexture("picture2"), pCamera, glm::vec3(-60.5f, 17.5f, 54.6f + resize), glm::vec3(0.18f, 0.55f, 0.25f), glm::radians(90.f), glm::vec3(-1.f, 0.f, 0.f), NULL);
		renderer->Draw(ResourceManager::GetTexture("picture3"), pCamera, glm::vec3(-74.5f, 17.5f, 40.f + resize), glm::vec3(0.18f, 0.55f, 0.25f), glm::radians(90.f), glm::vec3(0.f, 0.f, 1.f), 'z');
		renderer->Draw(ResourceManager::GetTexture("picture4"), pCamera, glm::vec3(-74.5f, 17.5f, 20 + resize), glm::vec3(0.18f, 0.55f, 0.25f), glm::radians(90.f), glm::vec3(0.f, 0.f, 1.f), 'z');
	}

	void Scene::RenderModels()
	{
		ModelShader modelShader("modelLoading.vs", "modelLoading.fs");

		modelShader.use();
		glm::mat4 projectionM = pCamera->GetProjectionMatrix();
		glm::mat4 viewM = pCamera->GetViewMatrix();
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "projection"), 1, GL_FALSE, glm::value_ptr(projectionM));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "view"), 1, GL_FALSE, glm::value_ptr(viewM));

		// First Room - Cristina


		glm::mat4 modelM = glm::mat4();
		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(-58.0f, -0.2f, -15.0f));
		modelM = glm::scale(modelM, glm::vec3(0.25f, 0.25f, 0.25f));
		modelM = glm::rotate(modelM, glm::radians(270.0f), glm::vec3(1.f, 0.f, 0.f));
		modelM = glm::rotate(modelM, glm::radians(45.0f), glm::vec3(0.f, 0.f, 1.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Bear").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(-42.0f, -0.2f, -13.7f));
		modelM = glm::scale(modelM, glm::vec3(0.12f, 0.15f, 0.12f));
		modelM = glm::rotate(modelM, glm::radians(270.0f), glm::vec3(1.f, 0.f, 0.f));
		modelM = glm::rotate(modelM, glm::radians(30.0f), glm::vec3(0.f, 0.f, 1.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Wolf").Draw(modelShader);


		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(-55.0f, -0.2f, 10.0f));
		modelM = glm::scale(modelM, glm::vec3(0.01f, 0.009f, 0.01f));
		modelM = glm::rotate(modelM, glm::radians(270.0f), glm::vec3(1.f, 0.f, 0.f));
		modelM = glm::rotate(modelM, glm::radians(125.0f), glm::vec3(0.f, 0.f, 1.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Horse").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(-59.0f, -0.2f, 2.0f));
		modelM = glm::scale(modelM, glm::vec3(0.1f, 0.12f, 0.1f));
		modelM = glm::rotate(modelM, glm::radians(270.0f), glm::vec3(1.f, 0.f, 0.f));
		modelM = glm::rotate(modelM, glm::radians(20.0f), glm::vec3(0.f, 0.f, 1.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Cat").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(-50.f, -0.5f, 0.f));
		modelM = glm::scale(modelM, glm::vec3(0.17f, 0.05f, 0.17f));
		modelM = glm::rotate(modelM, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Grass").Draw(modelShader);

		// Second Room - Cristina


		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(-15.0f, -0.5f, -20.0f));
		modelM = glm::scale(modelM, glm::vec3(0.1f, 0.1f, 0.1f));
		modelM = glm::rotate(modelM, glm::radians(270.0f), glm::vec3(1.f, 0.f, 0.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Pedastal").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(-15.0f, 6.5f, -20.0f));
		modelM = glm::scale(modelM, glm::vec3(0.1f, 0.1f, 0.1f));
		modelM = glm::rotate(modelM, glm::radians(270.0f), glm::vec3(1.f, 0.f, 0.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Skull_Dino").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(15.0f, -0.5f, -20.0f));
		modelM = glm::scale(modelM, glm::vec3(0.1f, 0.1f, 0.1f));
		modelM = glm::rotate(modelM, glm::radians(270.0f), glm::vec3(1.f, 0.f, 0.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Pedastal").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(15.0f, 6.5f, -20.0f));
		modelM = glm::scale(modelM, glm::vec3(0.1f, 0.1f, 0.1f));
		modelM = glm::rotate(modelM, glm::radians(270.0f), glm::vec3(1.f, 0.f, 0.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Skull_Dino").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(0.f, -0.5f, -20.0f));
		modelM = glm::scale(modelM, glm::vec3(0.7f, 0.6f, 0.7f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Human").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(0.f, 2.5f, -15.0f));
		modelM = glm::scale(modelM, glm::vec3(2.0f, 3.0f, 1.0f));
		modelM = glm::rotate(modelM, glm::radians(270.0f), glm::vec3(1.f, 0.f, 0.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Counter").Draw(modelShader);

		// Third Room - Andrei

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(50.f, -0.4f, -15.f));
		modelM = glm::scale(modelM, glm::vec3(0.08f, 0.1f, 0.05f));
		modelM = glm::rotate(modelM, glm::radians(270.f), glm::vec3(1.f, 0.f, 0.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Spinosaurus").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(37.f, 15.f, -15.f));
		modelM = glm::scale(modelM, glm::vec3(0.04f, 0.04f, 0.04f));
		modelM = glm::rotate(modelM, glm::radians(270.f), glm::vec3(1.f, 0.f, 0.f));
		modelM = glm::rotate(modelM, glm::radians(45.f), glm::vec3(0.f, 0.f, 0.5f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Quetzalcoatlus").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(33.f, 35.f, -10.f));
		modelM = glm::scale(modelM, glm::vec3(1.f, 7.2f, 1.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Wire").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(41.f, 35.f, -18.f));
		modelM = glm::scale(modelM, glm::vec3(1.f, 7.2f, 1.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Wire").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(39.2f, 32.9f, -12.f));
		modelM = glm::scale(modelM, glm::vec3(1.f, 8.2f, 1.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Wire").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(68.7f, 7.3f, -13.f));
		modelM = glm::scale(modelM, glm::vec3(8.f, 7.f, 5.f));
		modelM = glm::rotate(modelM, glm::radians(20.f), glm::vec3(0.f, -0.3f, 0.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Dilophosaurus").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(35.f, -0.3f, 15.f));
		modelM = glm::scale(modelM, glm::vec3(2.f, 3.3f, 1.5f));
		modelM = glm::rotate(modelM, glm::radians(45.f), glm::vec3(1.f, 0.f, 0.f));
		modelM = glm::rotate(modelM, glm::radians(45.f), glm::vec3(1.f, 0.f, 0.f));
		modelM = glm::rotate(modelM, glm::radians(180.f), glm::vec3(1.f, 0.f, 0.f));
		modelM = glm::rotate(modelM, glm::radians(315.f), glm::vec3(0.f, 0.f, 0.5f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Barosaurus").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(67.f, -0.35f, 14.f));
		modelM = glm::scale(modelM, glm::vec3(0.08f, 0.1f, 0.05f));
		modelM = glm::rotate(modelM, glm::radians(45.f), glm::vec3(1.f, 0.f, 0.f));
		modelM = glm::rotate(modelM, glm::radians(45.f), glm::vec3(1.f, 0.f, 0.f));
		modelM = glm::rotate(modelM, glm::radians(180.f), glm::vec3(1.f, 0.f, 0.f));
		modelM = glm::rotate(modelM, glm::radians(180.f), glm::vec3(0.f, 0.f, 0.5f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Cearadactylus").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(67.3f, -0.4f, 14.f));
		modelM = glm::scale(modelM, glm::vec3(3.f, 3.f, 3.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Podium").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(66.3f, -0.4f, -9.8f));
		modelM = glm::scale(modelM, glm::vec3(4.f, 4.f, 4.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Podium").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(50.f, -0.4f, -16.5f));
		modelM = glm::scale(modelM, glm::vec3(4.f, 4.f, 4.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Podium").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(34.5f, -0.4f, 16.5f));
		modelM = glm::scale(modelM, glm::vec3(4.f, 4.f, 4.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Podium").Draw(modelShader);

		// Sixth Room - Andrei

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(51.f, -0.5f, 51.25f));
		modelM = glm::scale(modelM, glm::vec3(0.085f, 0.07f, 0.085f));
		modelM = glm::rotate(modelM, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Grass").Draw(modelShader);

		float xCoordinate = 43.f;
		float zCoordinate = 55.f;

		for (int i = 0; i < 5; i++)
		{
			modelM = glm::mat4();
			modelM = glm::translate(modelM, glm::vec3(xCoordinate, -0.1f, zCoordinate));
			modelM = glm::scale(modelM, glm::vec3(0.4f, 0.3f, 0.4f));
			modelM = glm::rotate(modelM, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
			modelM = glm::rotate(modelM, glm::radians(-90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
			glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
			models->at("Daisy").Draw(modelShader);

			if (i < 1)
			{
				zCoordinate -= 6.f;
			}
			else if (i == 1)
			{
				xCoordinate += 0.5f;
				zCoordinate -= 6.f;
			}
			else
			{
				xCoordinate += 5.f;
			}
		}

		xCoordinate = 43.15f;
		zCoordinate = 52.5f;

		for (int i = 0; i < 4; i++)
		{
			modelM = glm::mat4();
			modelM = glm::translate(modelM, glm::vec3(xCoordinate, -0.1f, zCoordinate));
			modelM = glm::scale(modelM, glm::vec3(0.04f, 0.05f, 0.04f));
			modelM = glm::rotate(modelM, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
			models->at("Rose").Draw(modelShader);

			if (i < 1)
			{
				zCoordinate -= 6.f;
			}
			else if (i == 1)
			{
				xCoordinate += 3.f;
				zCoordinate -= 3.f;
			}
			else
			{
				xCoordinate += 5.f;
			}
		}

		xCoordinate = 45.f;
		zCoordinate = 54.f;

		for (int i = 0; i < 7; i++)
		{
			modelM = glm::mat4();
			modelM = glm::translate(modelM, glm::vec3(xCoordinate, -0.2f, zCoordinate));
			modelM = glm::scale(modelM, glm::vec3(0.185f, 0.25f, 0.2f));
			modelM = glm::rotate(modelM, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
			glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
			models->at("Tulip").Draw(modelShader);

			if (i < 3)
			{
				zCoordinate -= 3.f;
			}
			else
			{
				xCoordinate += 2.5f;
			}
		}

		xCoordinate = 43.f;
		zCoordinate = 57.f;

		for (int i = 0; i < 5; i++)
		{
			modelM = glm::mat4();
			modelM = glm::translate(modelM, glm::vec3(xCoordinate, -0.2f, zCoordinate));
			modelM = glm::scale(modelM, glm::vec3(0.35f, 0.5f, 0.35f));
			modelM = glm::rotate(modelM, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
			modelM = glm::rotate(modelM, glm::radians(-135.0f), glm::vec3(0.0f, 0.0f, 1.0f));
			glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
			models->at("Daffodil").Draw(modelShader);

			if (i < 1)
			{
				zCoordinate -= 6.f;
			}
			else if (i == 1)
			{
				xCoordinate += 0.5f;
				zCoordinate -= 6.f;
			}
			else
			{
				xCoordinate += 5.5f;
			}
		}

		xCoordinate = 41.f;
		zCoordinate = 54.2f;

		for (int i = 0; i < 9; i++)
		{
			modelM = glm::mat4();
			modelM = glm::translate(modelM, glm::vec3(xCoordinate, -0.2f, zCoordinate));
			modelM = glm::scale(modelM, glm::vec3(0.08f, 0.1f, 0.08f));
			modelM = glm::rotate(modelM, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
			modelM = glm::rotate(modelM, glm::radians(-135.0f), glm::vec3(0.0f, 0.0f, 1.0f));
			glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
			models->at("Crocus").Draw(modelShader);

			if (i < 3)
			{
				zCoordinate -= 3.f;
			}
			else if (i == 3)
			{
				xCoordinate += 1.75f;
				zCoordinate -= 1.85f;
			}
			else if (i == 4)
			{
				xCoordinate += 1.75f;
				zCoordinate -= 1.65f;
			}
			else
			{
				xCoordinate += 3.f;
			}
		}

		xCoordinate = 41.f;
		zCoordinate = 56.f;

		for (int i = 0; i < 10; i++)
		{
			modelM = glm::mat4();
			modelM = glm::translate(modelM, glm::vec3(xCoordinate, -0.2f, zCoordinate));
			modelM = glm::scale(modelM, glm::vec3(0.1f, 0.15f, 0.1f));
			modelM = glm::rotate(modelM, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
			modelM = glm::rotate(modelM, glm::radians(-135.0f), glm::vec3(0.0f, 0.0f, 1.0f));
			glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
			models->at("Anemone").Draw(modelShader);

			if (i < 3)
			{
				zCoordinate -= 3.25f;
			}
			else if (i == 3)
			{
				xCoordinate += 0.3f;
				zCoordinate -= 2.5f;
			}
			else if (i == 4 || i == 5)
			{
				xCoordinate += 2.25f;
				zCoordinate -= 1.5f;
			}
			else
			{
				xCoordinate += 2.95f;
			}
		}

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(51.5f, -0.25f, 52.f));
		modelM = glm::scale(modelM, glm::vec3(0.045f, 0.0375f, 0.045f));
		modelM = glm::rotate(modelM, glm::radians(90.f), glm::vec3(-1.0f, 0.f, 0.f));
		modelM = glm::rotate(modelM, glm::radians(135.f), glm::vec3(0.f, 0.f, -1.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Statue").Draw(modelShader);

		// Fifth Room - Cristina

		rotationAngle += 0.25f;

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(-1.5f, 0.f, 50.f));
		modelM = glm::scale(modelM, glm::vec3(0.1f, 0.1f, 0.1f));
		modelM = glm::rotate(modelM, glm::radians(235.f), glm::vec3(1.0f, 1.0f, 1.0f));
		modelM = glm::rotate(modelM, glm::radians(rotationAngle), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Vultur").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(-1.5f, -0.5f, 50.f));
		modelM = glm::scale(modelM, glm::vec3(0.05f, 0.05f, 0.05f));
		modelM = glm::rotate(modelM, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Grass").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(21.f, 10.f, 65.f));
		modelM = glm::scale(modelM, glm::vec3(0.2f, 0.2f, 0.2f));
		modelM = glm::rotate(modelM, glm::radians(235.f), glm::vec3(1.0f, 1.0f, 1.0f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Parrot").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(-20.f, -0.1f, 65.f));
		modelM = glm::scale(modelM, glm::vec3(0.3f, 0.3f, 0.3f));
		modelM = glm::rotate(modelM, glm::radians(235.f), glm::vec3(1.0f, 1.0f, 1.0f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Stork").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(-20.f, -0.4f, 68.f));
		modelM = glm::scale(modelM, glm::vec3(4.f, 4.f, 4.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Podium").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(-20.f, -0.1f, 30.f));
		modelM = glm::scale(modelM, glm::vec3(0.1f, 0.1f, 0.1f));
		modelM = glm::rotate(modelM, glm::radians(235.f), glm::vec3(1.0f, 1.0f, 1.0f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Pelican").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(-20.f, -0.4f, 32.f));
		modelM = glm::scale(modelM, glm::vec3(4.f, 4.f, 4.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Podium").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(17.f, 1.8f, 32.f));
		modelM = glm::scale(modelM, glm::vec3(0.07f, 0.07f, 0.07f));
		modelM = glm::rotate(modelM, glm::radians(235.f), glm::vec3(1.0f, 1.0f, 1.0f));
		modelM = glm::rotate(modelM, glm::radians(90.f), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Duck").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(17.f, -0.4f, 33.f));
		modelM = glm::scale(modelM, glm::vec3(4.f, 4.f, 4.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Podium").Draw(modelShader);

		// Fourth Room - Andrei
		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(-50.f, 1.75f, 61.f));
		modelM = glm::scale(modelM, glm::vec3(2.f, 2.f, 2.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Pedastal2").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(-50.f, 5.f, 60.5f));
		modelM = glm::scale(modelM, glm::vec3(0.1f, 0.1f, 0.1f));
		modelM = glm::rotate(modelM, glm::radians(90.f), glm::vec3(-1.0f, 0.0f, 0.0f));
		modelM = glm::rotate(modelM, glm::radians(90.f), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Fish1").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(-38.f, 1.75f, 52.f));
		modelM = glm::scale(modelM, glm::vec3(2.f, 2.f, 2.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Pedastal2").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(-38.f, 4.f, 52.f));
		modelM = glm::scale(modelM, glm::vec3(0.4f, 0.4f, 0.4f));
		modelM = glm::rotate(modelM, glm::radians(90.f), glm::vec3(-1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Fish2").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(-62.f, 1.75f, 52.f));
		modelM = glm::scale(modelM, glm::vec3(2.f, 2.f, 2.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Pedastal2").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(-62.f, 5.f, 52.f));
		modelM = glm::scale(modelM, glm::vec3(0.25f, 0.25f, 0.25f));
		modelM = glm::rotate(modelM, glm::radians(90.f), glm::vec3(0.0f, 1.0f, 0.0f));
		modelM = glm::rotate(modelM, glm::radians(90.f), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Fish3").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(-56.f, 1.75f, 42.f));
		modelM = glm::scale(modelM, glm::vec3(2.f, 2.f, 2.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Pedastal2").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(-43.85f, 4.f, 42.5f));
		modelM = glm::scale(modelM, glm::vec3(1.f, 1.f, 1.f));
		modelM = glm::rotate(modelM, glm::radians(90.f), glm::vec3(-1.0f, 0.0f, 0.0f));
		modelM = glm::rotate(modelM, glm::radians(180.f), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Fish4").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(-44.f, 1.75f, 42.f));
		modelM = glm::scale(modelM, glm::vec3(2.f, 2.f, 2.f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Pedastal2").Draw(modelShader);

		modelM = glm::mat4();
		modelM = glm::translate(modelM, glm::vec3(-56.f, 4.f, 42.f));
		modelM = glm::scale(modelM, glm::vec3(0.5f, 0.5f, 0.5f));
		modelM = glm::rotate(modelM, glm::radians(90.f), glm::vec3(-1.0f, 0.0f, 0.0f));
		modelM = glm::rotate(modelM, glm::radians(90.f), glm::vec3(0.0f, 0.0f, -1.0f));
		glUniformMatrix4fv(glGetUniformLocation(modelShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(modelM));
		models->at("Fish5").Draw(modelShader);


	}