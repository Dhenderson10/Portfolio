using UnityEngine;
using System.Collections;

public class GameMaster : MonoBehaviour {

	public int enemyAmount;
	GameMaster MASTER = new GameMaster();
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


	
}
