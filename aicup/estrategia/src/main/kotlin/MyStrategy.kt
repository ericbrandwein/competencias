import model.*

class MyStrategy {
    fun getAction(playerView: PlayerView, debugInterface: DebugInterface?): Action {
        val actions = mutableMapOf<Int, EntityAction>()
        playerView.entities
            .filter { it.playerId == playerView.myId }
            .forEach { entity ->
                val entityProperties = playerView.entityProperties[entity.entityType]!!
                var moveAction: MoveAction? = null
                var buildAction: BuildAction? = null
                if (entityProperties.canMove) {
                    moveAction = MoveAction(
                        Vec2Int(playerView.mapSize - 1, playerView.mapSize - 1),
                        findClosestPosition = true,
                        breakThrough = true
                    )
                } else if (entityProperties.build != null) {
                    buildAction = BuildAction(
                        entityProperties.build!!.options[0],
                        Vec2Int(
                            entity.position.x + entityProperties.size,
                            entity.position.y + entityProperties.size - 1
                        )
                    )
                }
                val autoAttackTargets = mutableListOf<EntityType>()
                if (entity.entityType == EntityType.BUILDER_UNIT) {
                    autoAttackTargets.add(EntityType.RESOURCE)
                }
                actions[entity.id] = EntityAction(
                    moveAction,
                    buildAction,
                    AttackAction(
                        null,
                        AutoAttack(entityProperties.sightRange, autoAttackTargets.toTypedArray())
                    ),
                    null
                )
            }
        return Action(actions)
    }
    fun debugUpdate(playerView: PlayerView, debugInterface: DebugInterface) {
        debugInterface.send(model.DebugCommand.Clear())
        debugInterface.getState()
    }
}
