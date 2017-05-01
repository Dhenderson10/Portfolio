using UnityEngine;
using System.Collections;

public class SkellyShoot : MonoBehaviour {


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
	public bool hitPlayer = false;
	GameObject p1;
	public bool isDead = false;

	//	public Transform TestBullet;
	public Sprite attack;
	public Sprite idle;
	public SpriteRenderer hey;





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
		
		hey.sprite = idle;
		if (fireRate == 0) 
		{
			if (xVal < 2) 
			{
			
				Shoot ();
				fireRate = 1;

			} 
			else 
			{
				//hey.sprite = idle;
			}
		} 
		else 
		{
			
			if (xVal < 2 && Time.time > timeToFire) {
				
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
		} 
		else 
		{
			hitPlayer = false;
		}


		if (Time.time >= timeToSpawnEffect) 
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

		float rightX = firePoint.position.x - (float)0.5;
		float leftX = firePoint.position.x + (float)0.5;


		Vector3 rightBulletShift = new Vector3 (rightX, firePoint.position.y);
		Vector3 leftBulletShift = new Vector3 (leftX, firePoint.position.y);
		//attackani.StopPlayback();
	

		Instantiate (FriendlyBulletsPrefab, rightBulletShift, firePoint.rotation);
		Instantiate (FriendlyBulletsPrefab, leftBulletShift, firePoint.rotation);
		Instantiate (FriendlyBulletsPrefab, firePoint.position, firePoint.rotation);
		/*hey.sprite = attack;
		for (int i = 0; i < 10000; i++) {
			hey.sprite = attack;
		}
		hey.sprite = idle;*/
		//orig.sprite = 
		//wait();
	}
	IEnumerator wait()
	{
		hey.sprite = attack;
		yield return new WaitForSeconds (4);
		Time.timeScale = 0;
		hey.sprite = idle;

	}
	public bool returnHit()
	{
		return hitPlayer;
	}
}
