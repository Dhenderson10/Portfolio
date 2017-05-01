using UnityEngine;
using System.Collections;

public class Shoot : MonoBehaviour {
	public GameObject Bullet;
	protected GameObject MovingBullet;
	public Weapon w1 = new Weapon();

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {

		if (Input.GetButtonDown ("Fire1")) {
			MovingBullet = Instantiate<GameObject> (Bullet);
		}

		MovingBullet.transform.Translate (Vector3.up);
		//Debug.Log (Weapon.hit.collider.tag);
		if(MovingBullet.transform.position.x > 20 || Weapon.hit.collider.tag == "Cover")
		{
			Debug.Log ("this should be destroyed");
			MovingBullet.transform.localScale = new Vector3 (0, 0, 0);
		

		}

				
	
	}
}
