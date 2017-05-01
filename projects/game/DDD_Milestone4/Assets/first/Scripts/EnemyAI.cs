using UnityEngine;
using System.Collections;

public class EnemyAI : MonoBehaviour {

	public string ID = "enemy";

	public class EnemyStats
	{
		public float Health = 100f;
	}
	//GameObject p1 = GameObject.Find ("Player");

	public bool what;
	public EnemyStats enemyStats = new EnemyStats();
	
	//public Weapon lol = new Weapon();


	void Update ()
	{

	}

	public void DamageEnemy (int damage)
	{
		enemyStats.Health -= damage;

		if (enemyStats.Health <= 0) 
		{
			//GameMaster.KillEnemy (this);
		}
	}
}
