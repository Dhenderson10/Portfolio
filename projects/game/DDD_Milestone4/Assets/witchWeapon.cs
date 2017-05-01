using UnityEngine;
using System.Collections;

public class witchWeapon : MonoBehaviour {

	// Use this for initialization
	public float fireRate = 0;
	public float damage = 10;
	public LayerMask whatToHit;
	public Transform FriendlyBulletsPrefab;
	float timeToSpawnEffect = 0;
	float timeToFire = 0;
	float effectSpawnRate = 10;
	float xVal;
	float yVal;
	Transform firePoint;
	public bool hitPlayer = true;
	GameObject p1;
	public bool isDead = false;

	public bool doNotFire = false;
	//	public Transform TestBullet;




	Player.PlayerStats player = new Player.PlayerStats ();

	// Use this for initialization
	void Awake () 
	{
		p1 = GameObject.Find ("Player");
		firePoint = transform.FindChild ("FirePointEnemy");
		if (firePoint == null) 
		{
			Debug.LogError ("NO FIREPOINT");
		}
	}




	// Update is called once per frame
	void Update () 
	{
		if (fireRate == 0) 
		{
			if (xVal < 2 ) 
			{
				Shoot ();
				fireRate = 1;

			}
		} 
		else 
		{
			if (xVal < 2 && Time.time > timeToFire )
			{
				timeToFire = Time.time + 1 / fireRate;
				Shoot ();
				fireRate = 0;

			}

		}
		xVal = p1.transform.position.x;
		yVal = p1.transform.position.y;


	}


	void Shoot () 
	{

		Vector2 playerPosition = new Vector2 ( xVal , yVal );
		Vector2 firePointPosition = new Vector2 ( firePoint.position.x, firePoint.position.y );

		RaycastHit2D hit = Physics2D.Raycast ( firePointPosition, playerPosition-firePointPosition, 100, whatToHit); 
		//third arg here is distance so we can set this in case we wanna have short distance for certain
		//weapons aka magic and shotguns and shittttttt

		//Debug.DrawLine (firePointPosition, (playerPosition-firePointPosition)*100, Color.blue);
		if (hit.collider != null && isDead == false) 
		{
			hitPlayer = true;
			//Debug.DrawLine (firePointPosition, hit.point, Color.red);
			//Debug.Log ("hit " + hit.collider.name + " for " + damage + " damage.");
			if (hit.collider.gameObject.tag == "Cover") 
			{
				doNotFire = true;

			} 
			else 
			{
				doNotFire = false;

			}

		} 
		else 
		{
			hitPlayer = false;
		}





		if (Time.time >= timeToSpawnEffect && doNotFire == false ) 
		{
			Effect ();
			timeToSpawnEffect = Time.time + 1 / effectSpawnRate;
		}

	}


	void Effect ()
	{
		//actually fires the bullet
		bool delayWeaponFire = true;
		int rng;
		while (delayWeaponFire) {
			rng = Random.Range (0, 100000);
			if (rng == 500) {
				delayWeaponFire = false;
			}
		}
		//FriendlyBulletsPrefab.localScale.x = 4;
		//FriendlyBulletsPrefab.localScale.y = 4;
		Instantiate (FriendlyBulletsPrefab, firePoint.position, firePoint.rotation);

	}

	public bool returnHit()
	{
		return hitPlayer;
	}

}
