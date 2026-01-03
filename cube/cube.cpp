#include <Ogre.h>
#include <OgreApplicationContext.h>

auto main() -> int {
  OgreBites::ApplicationContext ctx("Cube");
  ctx.initApp();

  Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
      // TODO: find a way to make this directory always point to the right place
      "cube/mesh/", "FileSystem",
      Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

  Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

  Ogre::Root *root = ctx.getRoot();
  Ogre::SceneManager *scnMgr = root->createSceneManager();

  Ogre::RTShader::ShaderGenerator *shadergen =
      Ogre::RTShader::ShaderGenerator::getSingletonPtr();
  shadergen->addSceneManager(scnMgr);

  Ogre::Light *light = scnMgr->createLight("MainLight");
  Ogre::SceneNode *lightNode =
      scnMgr->getRootSceneNode()->createChildSceneNode();
  // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers)
  lightNode->setPosition(0, 10, 15);
  lightNode->attachObject(light);

  Ogre::SceneNode *camNode = scnMgr->getRootSceneNode()->createChildSceneNode();
  // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers)
  camNode->setPosition(0, 0, 15);
  camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);

  Ogre::Camera *cam = scnMgr->createCamera("myCam");
  // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers)
  cam->setNearClipDistance(5);
  cam->setAutoAspectRatio(true);
  camNode->attachObject(cam);

  ctx.getRenderWindow()->addViewport(cam);

  Ogre::Entity *ent = scnMgr->createEntity("Cube.mesh");
  Ogre::SceneNode *node = scnMgr->getRootSceneNode()->createChildSceneNode();
  // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers)
  node->pitch(Ogre::Degree(-45));
  // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers)
  node->yaw(Ogre::Degree(-15));
  node->attachObject(ent);

  ctx.getRoot()->startRendering();
  ctx.closeApp();

  return 0;
}
