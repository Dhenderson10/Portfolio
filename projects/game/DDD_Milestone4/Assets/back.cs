using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class back : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKeyDown (KeyCode.Space) == true) {
			SceneManager.LoadScene (0);
		}
	
	}
}
