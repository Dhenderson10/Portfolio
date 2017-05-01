using UnityEngine;
using System.Collections;

public class MoveBullets : MonoBehaviour {
	EnemyWeapon weapon = new EnemyWeapon();
	EnemyAI enemy = new EnemyAI();
	public int moveSpeed = 2;
	public bool playerHit;
	public int killCount = 0;
	//Health m = new Health();
	//public GameObject player = GameObject.Find("Player");

	void start()
	{
		//m.health = 3;
		playerHit = false;
	}
	// Update is called once per frame
	void Update () {
		transform.Translate (Vector3.right * Time.deltaTime * moveSpeed);
		//Debug.Log (this.gameObject.tag);
		//if (this.gameObject.tag == "Enemy") 
		//{

			Destroy (this.gameObject, 5);
			this.weapon.isDead = true;

	
	}

	void OnCollisionEnter2D(Collision2D coll) 
	{
		//if (coll.gameObject.tag == "Enemy")
		//	coll.gameObject.SendMessage("ApplyDamage", 10);
		Debug.Log("HIT");
	}

	public void DestroyBullet()
	{
		Destroy (this.gameObject);
	}

	public bool isPlayerHit()
	{
		if (playerHit == false) {
			return false;
		} else {
			return true;
		}
	}
}
