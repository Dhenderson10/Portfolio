using UnityEngine;
using System.Collections;

public class Player : MonoBehaviour {

	public class PlayerStats 
	{
		public float Health = 300f;
		public float xVal;
		public float yVal;

	}

	void onCollisionEnter (Collision col)
	{
		if (col.gameObject.name == "Player") {
			Debug.Log ("I Hit it");
		}

	}
		
	EnemyWeapon hey = new EnemyWeapon();


	public PlayerStats playerStats = new PlayerStats();

	void Update ()
	{
		playerStats.xVal = transform.position.x;
		playerStats.yVal = transform.position.y;


	}
		

	public void DamagePlayer (int damage)
	{
		playerStats.Health -= damage;

		if (playerStats.Health <= 0) 
		{
			//GameMaster.KillPlayer (this);
		}
	}

}
