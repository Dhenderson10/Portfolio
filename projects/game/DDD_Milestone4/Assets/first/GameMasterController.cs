using UnityEngine;
using System.Collections;

public class GameMasterController : MonoBehaviour {

	// Use this for initialization

	public int enemyAmount = 4;

	void start()
	{
		enemyAmount = 4;
	}
	public static void KillPlayer (Player player)
	{
		Destroy (player.gameObject);
	}

	public static void KillEnemy ( EnemyAI enemy)
	{
		Destroy (enemy.gameObject);
	}



	void update()
	{
		
	}
}
