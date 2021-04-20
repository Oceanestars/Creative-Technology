//
//  ViewController.swift
//  favorite
//
//  Created by Oceane Andreis on 4/5/21.
//

import UIKit

class ViewController: UIViewController {

    
    @IBOutlet weak var imageFavorite: UIImageView!
    @IBOutlet weak var messageText: UILabel!
    @IBAction func pickFavorite(_ sender: UIButton) {
        if sender.tag == 1{
            messageText.text = "Sushi is obviously the best"
            imageFavorite.image = UIImage(named: "sushi")
        } else{
            messageText.text = "The rest of the foods are acceptable"
            imageFavorite.image = UIImage(named: "pasta")
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }


}

