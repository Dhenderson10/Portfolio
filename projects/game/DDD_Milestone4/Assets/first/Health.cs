using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class Health : MonoBehaviour {
	public static Text text;
	public bool decrementHealth = false;
	public int health = 3;
	public int max = 3;
	//public MoveBullets m = new MoveBullets ();
	// Use this for initialization
	void Start () {
		health = 3;
		text = GetComponentInParent<Text> ();
	}
	
	// Update is called once per frame
	void Update () {
		if (health < max) {
			//health--;
			//text.text = "HEALTH: " + health + "/3";
			//max = health;
			//decrementHealth = false;
		}
	
	}
}
